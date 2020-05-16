#include "../base/icode.hpp"
class L169 : public icode
{
public:
    int majorityElement(vector<int> &nums)
    {
        int cur = nums[0], time = 1, i = 1;
        for (; i < (int)nums.size(); ++i)
        {
            if (time <= 0)
            {
                cur = nums[i];
                time = 1;
            }
            else
            {
                if (nums[i] == cur)
                {
                    ++time;
                }
                else
                {
                    --time;
                }
            }
        }
        return cur;
    }

    void run()
    {
        vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
        cout << majorityElement(nums) << endl;
    }
};