#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <chrono>
#include <future>

void Combination(size_t m, size_t index, size_t sub_size, std::string &result, std::vector<char> &leaves);

void Combination1(std::vector<char> &leaves)
{
    std::string result;
    for (size_t i = 1, length = leaves.size(); i <= length; i++)
        Combination(i, 0, i, result, leaves);
    std::cout << result << std::endl;
}

void Combination(size_t m, size_t index, size_t sub_size, std::string &result, std::vector<char> &leaves)
{
    if (m == 0)
    {
        std::cout << result << std::endl;
        return;
    }
    size_t length = leaves.size();
    if (index + m > length)
        return;
    result += leaves[index];
    Combination(m - 1, index + 1, sub_size, result, leaves);
    if (sub_size == length)
        return;
    result.pop_back();
    Combination(m, index + 1, sub_size, result, leaves);
}

void Combination2(std::vector<char> &leaves)
{
    size_t num_leaf = leaves.size();
    bool cur[num_leaf + 1] = {0};
    *cur = 1;
    size_t threshold = 1;
    while (threshold <= num_leaf)
    {
        size_t k = 0, j = 0;
        bool *p = cur;
        for (j = 0; j < threshold; j++)
        {
            if (*(p++))
            {
                k++;
                std::cout << leaves[j];
            }
        }
        std::cout << "; " << k << " -> " << threshold << std::endl;
        // update cur
        j = 0;
        p = cur;
        while (j++ <= threshold && !(*(p++) ^= true))
            ;
        if (j >= threshold)
            ++threshold;
    }
}

void Combination3(std::vector<char> &leaves)
{
    size_t num_leaf = leaves.size();
    std::queue<std::pair<size_t, std::string>> que;
    for (size_t i = 0; i < num_leaf; i++)
    {
        que.emplace(i, std::string(1, leaves[i]));
    }
    size_t k = 1, num = num_leaf;
    while (!que.empty())
    {
        size_t _num = 0;
        for (size_t i = 0; i < num; ++i)
        {
            std::pair<size_t, std::string> &cur = que.front();
            que.pop();
            std::cout << cur.second << "; " << k << std::endl;
            for (size_t j = cur.first + 1; j < num_leaf; j++)
            {
                que.emplace(j, cur.second + leaves[j]);
            }
            _num += num_leaf - cur.first - 1;
        }
        ++k;
        num = _num;
    }
}

void Combination4(std::vector<char> &leaves)
{
    size_t num_leaf = leaves.size();
    std::vector<std::pair<size_t, std::string>> que_1;
    std::vector<std::pair<size_t, std::string>> que_2;
    for (size_t i = 0; i < num_leaf; i += 2)
    {
        que_1.emplace_back(i, std::string(1, leaves[i]));
        if (i + 1 < num_leaf)
            que_2.emplace_back(i + 1, std::string(1, leaves[i + 1]));
    }
    size_t k = 1;
    while (!que_1.empty() || !que_2.empty())
    {
        std::future<std::vector<std::pair<size_t, std::string>>> ft1 = async(std::launch::async, [&]
                                                                             {
          std::vector<std::pair<size_t, std::string>> _que;      
          for (size_t i = 0, num = que_1.size(); i < num; i++) {
              std::pair<size_t, std::string> &cur = que_1[i];
            std::cout << cur.second << "; " << k << std::endl;
            for (size_t j = cur.first + 1; j < num_leaf; j++)
            {
                _que.emplace_back(j, cur.second + leaves[j]);
            }
          }
          return _que; });

        std::future<std::vector<std::pair<size_t, std::string>>> ft2 = async(std::launch::async, [&]
                                                                             {
        std::vector<std::pair<size_t, std::string>> _que;
          for (size_t i = 0, num = que_2.size(); i < num; i++) {
              std::pair<size_t, std::string> &cur = que_2[i];
            std::cout << cur.second << "; " << k << std::endl;
            for (size_t j = cur.first + 1; j < num_leaf; j++)
            {
                _que.emplace_back(j, cur.second + leaves[j]);
            }
          }
          return _que; });

        que_1 = ft1.get();
        que_2 = ft2.get();
        ++k;
    }
}

int main()
{
    std::vector<char> leaves = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    auto start = std::chrono::steady_clock::now();
    Combination1(leaves);
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double, std::micro> elapsed = end - start;
    std::cout << "time: " << elapsed.count() << "us" << std::endl;
    return 0;
}