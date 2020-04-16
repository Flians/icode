#include "../base/icode.h"

class L704 : public icode
{
public:
    int search(std::vector<int> &nums, int target, int left, int right)
    {
        if (left < 0 || right < 0 || left > right)
            return -1;
        if (left == right)
        {
            return target == nums.at(left) ? left : -1;
        }
        int mid = (left + right) / 2;
        if (target == nums.at(mid))
            return mid;
        //right is consensus
        if (nums.at(right) > nums.at(mid))
        {
            if (target > nums.at(mid) && target <= nums.at(right))
            {
                return search(nums, target, mid + 1, right);
            }
            else
            {
                return search(nums, target, left, mid - 1);
            }
        }
        //right is unconsensus
        else if (nums.at(right) < nums.at(mid))
        {
            if (target < nums.at(mid) && target >= nums.at(left))
            {
                return search(nums, target, left, mid - 1);
            }
            else
            {
                return search(nums, target, mid + 1, right);
            }
        }
        else
        {
            return right;
        }
    }
    int search(vector<int> &nums, int target)
    {
        return search(nums, target, 0, nums.size() - 1);
    }

    void run()
    {
        int target = 3;
        int num[5] = {9, 0, 2, 7, 8};
        std::vector<int> nums(num, num + 5);
        // nums.insert(nums.begin(), num, num + 5);
        std::cout << search(nums, target, 0, nums.size() - 1) << std::endl;
    }
};
