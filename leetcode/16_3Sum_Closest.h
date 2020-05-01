#include "../base/icode.h"
class L16 : public icode
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        if ((int)nums.size() < 3)
            return 0;
        int closest = nums[0] + nums[1] + nums[2], i = 0, j = 0, k = 0;
        sort(nums.begin(), nums.end());
        for (; i < (int)nums.size() - 2; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            j = i + 1;
            k = nums.size() - 1;
            while (j < k)
            {
                int temp = nums[i] + nums[j] + nums[k];
                if (temp == target)
                    return target;
                if (abs(temp - target) < abs(closest - target))
                    closest = temp;
                if (temp > target)
                    k--;
                else
                    j++;
            }
        }
        return closest;
    }

    void run()
    {
        vector<int> nums = {-1, 2, 1, -4};
        cout << threeSumClosest(nums, 1) << endl;
    }
};