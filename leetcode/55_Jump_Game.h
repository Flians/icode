#include "../base/icode.h"

class L55 : public icode
{
public:
    bool canJump(vector<int> &nums)
    {
        if (nums.size() <= 1)
            return true;
        int i = 0, maxP = 1;
        while (maxP-- && i < (int)nums.size())
        {
            maxP = max(nums[i++], maxP);
            if (i + maxP >= (int)nums.size())
                break;
        }
        return i < (int)nums.size() && maxP > 0;
    }

    void run()
    {
        vector<int> nums = {3, 2, 1, 0, 4};
        cout << canJump(nums) << endl;
    }
};