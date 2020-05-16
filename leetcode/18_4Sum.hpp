#include "../base/icode.hpp"
class L18 : public icode
{
public:
    void findSum(vector<int> item, int index, vector<int> &nums, int target, vector<vector<int>> &result)
    {
        if (item.size() == 4)
        {
            if (target == 0)
            {
                result.push_back(item);
            }
        }
        else
        {
            if (index < (int)nums.size())
            {
                findSum(item, index + 1, nums, target, result);
                item.push_back(nums[index]);
                findSum(item, index + 1, nums, target - nums[index], result);
            }
        }
    }

    void threeSum(int index, vector<int> &nums, int target, vector<vector<int>> &result)
    {
        int first = nums[index - 1];
        bool flag = false;
        for (; index < (int)nums.size() - 1; index++)
        {
            if (flag && nums[index] == nums[index - 1])
                continue;
            flag = true;
            int left = index + 1;
            int right = nums.size() - 1;
            while (left < right)
            {
                if (nums[index] + nums[left] + nums[right] < target)
                {
                    left++;
                }
                else if (nums[index] + nums[left] + nums[right] > target)
                {
                    right--;
                }
                else
                {
                    vector<int> item;
                    item.push_back(first);
                    item.push_back(nums[index]);
                    item.push_back(nums[left]);
                    item.push_back(nums[right]);
                    result.push_back(item);
                    left++;
                    right--;
                    while (left < right && nums[left] == nums[left - 1])
                        left++;
                    while (left < right && nums[right] == nums[right + 1])
                        right--;
                }
            }
        }
    }

    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> result;
        if (nums.size() >= 4)
        {
            int i = 0;
            sort(nums.begin(), nums.end());
            for (; i < (int)nums.size() - 3; i++)
            {
                if (i == 0 || nums[i] != nums[i - 1])
                {
                    /*
                    vector<int> item;
                    findSum(item,i+1, nums, target, result);
                    item.push_back(nums[i]);
                    findSum(item,i+1, nums, target-nums[i], result);
                    */
                    threeSum(i + 1, nums, target - nums[i], result);
                }
            }
            /*
            sort(result.begin(), result.end());
            result.erase(unique(result.begin(),result.end()), result.end());
            */
        }
        return result;
    }

    void run()
    {
        vector<int> nums = {1, 0, -1, 0, -2, 2};
        print_res(fourSum(nums, 0));
    }
};