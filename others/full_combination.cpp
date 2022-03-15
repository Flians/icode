#include <iostream>
#include <vector>
#include <string>
#include <queue>

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
    if (index + m > leaves.size())
        return;
    result += leaves[index];
    Combination(m - 1, index + 1, sub_size, result, leaves);
    if (sub_size == leaves.size())
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
    size_t k = 1;
    while (!que.empty())
    {
        for (size_t i = 0, num = que.size(); i < num; ++i)
        {
            std::pair<size_t, std::string> cur = que.front();
            que.pop();
            std::cout << cur.second << "; " << k << std::endl;
            for (size_t j = cur.first + 1; j < num_leaf; j++)
            {
                que.emplace(j, cur.second + leaves[j]);
            }
        }
        ++k;
    }
}

int main()
{
    std::vector<char> leaves = {'A', 'B', 'C', 'D', 'E'};
    Combination3(leaves);
    return 0;
}