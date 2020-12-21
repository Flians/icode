#include "../base/icode.hpp"

class L334 : public icode
{
public:
    bool increasingTriplet(vector<int> &nums)
    {
        if (nums.size() < 3)
            return false;
        int fir = nums[0], sec = INT_MAX;
        size_t i = 1;
        for (; i < nums.size(); ++i)
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
        cout << increasingTriplet(nums) << " true" << endl;
    }
};