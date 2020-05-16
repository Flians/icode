#include "../base/icode.hpp"

class L560 : public icode
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        if (nums.empty())
            return -1;
        map<int, int> sum;
        int i = 0, ts = 0, res = 0;
        sum[0] = 1;
        for (; i < (int)nums.size(); ++i)
        {
            ts = nums[i] + ts;
            if (sum.count(ts - k))
                res += sum[ts - k];
            sum[ts] += 1;
        }
        return res;
    }

    void run()
    {
        vector<int> nums = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        cout << subarraySum(nums, 0) << endl;
    }
};