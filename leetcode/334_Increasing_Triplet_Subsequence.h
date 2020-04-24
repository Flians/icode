#include "../base/icode.h"

class L334 : public icode
{
public:
    bool increasingTriplet(vector<int> &nums)
    {
        if (nums.size() < 3)
            return false;
        int fir = nums[0], sec = INT_MAX, i = 1;
        for (; i < (int)nums.size(); ++i)
        {
            if (nums[i] > sec)
            {
                return true;
            }
            else if (nums[i] > fir)
            {
                sec = nums[i];
            }
            else
            {
                fir = nums[i];
            }
        }
        return false;
    }

    void run()
    {
        vector<int> nums = {1, 2, 3, 4, 5};
        cout << increasingTriplet(nums) << endl;
    }
};