#include <iostream>
#include <vector>
#include <string>

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
    std::string nBit_str(num_leaf, '0');
    nBit_str.append("1");
    std::string cur = "1";
    cur.append(num_leaf, '0');
    size_t threshold = 1;
    while (cur != nBit_str)
    {
        size_t k = 0, j = 0;
        for (j = 0; j < threshold; j++)
        {
            if (cur[j] == '1')
            {
                k++;
                std::cout << leaves[j];
            }
        }
        std::cout << "; " << k << " -> " << cur << std::endl;
        for (j = 0; j <= threshold; ++j)
        {
            if (cur[j] == '1')
            {
                cur[j] -= 1;
            }
            else
            {
                cur[j] += 1;
                break;
            }
        }
        if (j == threshold)
            ++threshold;
    }
}

int main()
{
    std::vector<char> leaves = {'A', 'B', 'C', 'D', 'E'};
    Combination2(leaves);
    return 0;
}