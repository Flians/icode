/*
http://theory.ict.ac.cn/grad_oj/problem/32
Problem description:
There are N Monkeys and N bananas are placed in a straight line. Each monkey want to have a banana, if two monkeys want to own the same banana, there will be a fight! A monkey can stay at his position, move one step right from x to x + 1, or move one step left from x to x -1. Any of these moves consumes 1 second. Assign monkeys to banana so that not monkey fight each other and the time when the last monkey gets a banana is minimized.

Input:
The input contain two arrays of int. The first array is the positions of monkeys. The second array is the positions of bananas.

Output:
The output is a int, which is the time(in seconds) it takes when all bananas are assigned to monkeys.

Sample input:
1 3 6
2 4 6
Sample output:
1
Sample explanation:
Assign monkey at position 1 to banana at position 2. (1 second)

Assign monkey at position 3 to banana at position 4. (1 second)

Assign monkey at position 6 to banana at position 6. (0 second)

Overall time is max(1, 1, 0) = 1 second.
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

int assign_banana_to_monkeys(std::vector<int> monkey, std::vector<int> banana)
{
    int maxt=0, i=0;
    if (monkey.size() != banana.size())
        return -1;
    for(; i < (int)monkey.size(); i++)
    {
        maxt = std::max(maxt, std::abs(monkey.at(i)-banana.at(i)));
    }
    return maxt;
}

int main(int argc, char const *argv[])
{
    std::vector<int> monkeys;
    std::vector<int> banana;
    int temp = 0;

    std::cin >> temp;
    monkeys.push_back(temp);
    while (std::cin.get() != '\n')
    {
        std::cin >> temp;
        monkeys.push_back(temp);
    }
    std::sort(monkeys.begin(), monkeys.end());

    std::cin >> temp;
    banana.push_back(temp);
    while (std::cin.get() != '\n')
    {
        std::cin >> temp;
        banana.push_back(temp);
    }
    std::sort(banana.begin(), banana.end());
    std::cout << assign_banana_to_monkeys(monkeys, banana) << std::endl;
    return 0;
}
