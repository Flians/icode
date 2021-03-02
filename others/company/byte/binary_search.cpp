#include <iostream>
#include <vector>

int find_min(std::vector<int> &&nums)
{
    int l = 0, r = nums.size() - 1;
    while (l < r)
    {
        if (nums[l] < nums[r])
        {
            return nums[l];
        }
        int mid = (l + r) / 2;
        if (nums[l] <= nums[mid])
        {
            l = mid + 1;
        }
        else
        {
            r = mid;
        }
    }
    return nums[l];
}

int main()
{
    std::cout << find_min({4, 5, 6, 7, 1, 2, 3}) << " 1" << std::endl;
    std::cout << find_min({4, 5, 6, 7, 1, 2}) << " 1" << std::endl;
    return 0;
}
