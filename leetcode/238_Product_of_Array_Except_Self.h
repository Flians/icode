#include "../base/icode.h"

class L238 : public icode
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int i = 0;
        vector<int> outs(nums.size(), 1);
        for (i = 1; i < nums.size(); ++i)
        {
            outs[i] = outs[i - 1] * nums[i - 1];
        }
        int right = 1;
        for (i = nums.size() - 1; i >= 0; --i)
        {
            outs[i] *= right;
            right *= nums[i];
        }
        return outs;
    }

    void run()
    {
    }
};