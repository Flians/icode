#include <iostream>
#include <vector>
#include <string>

void Combination(int m, int index, int sub_size, std::vector<char> &leaves, std::string &result);

void Combination1(std::vector<char> &leaves)
{
    std::string result;
    for (size_t i = 1, length = leaves.size(); i <= length; i++)
        Combination(i, 0, i, leaves, result);
}

void Combination(int m, int index, int sub_size, std::vector<char> &leaves, std::string &result)
{
    if (m == 0)
    {
        std::cout << result << std::endl;
        return;
    }
    if (index + m > leaves.size())
        return;
    result += leaves[index];
    Combination(m - 1, index + 1, sub_size, leaves, result);
    if (sub_size == leaves.size())
        return;
    result.pop_back();
    Combination(m, index + 1, sub_size, leaves, result);
}

void Combination2(std::vector<char> &leaves)
{
    size_t num_leaf = leaves.size();
    uint64_t nBit = 1 << num_leaf;
    for (uint64_t i = 1; i < nBit; i++)
    {
        size_t k = 0;
        for (size_t j = 0; j < num_leaf; j++)
        {
            if (i & (1 << j))
            {
                k++;
                std::cout << leaves[j];
            }
        }
        std::cout << "; " << k << " -> " << i << std::endl;
    }
}

int main()
{
    std::vector<char> leaves = {'A', 'B', 'C', 'D'};
    Combination2(leaves);
    return 0;
}