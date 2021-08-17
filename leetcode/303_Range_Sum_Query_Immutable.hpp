#include "../base/icode.hpp"
class NumArray : public icode
{
public:
    vector<int> &preSum;
    vector<int> _default = {1, 2, 3, 4};

    void run()
    {
        NumArray *obj = new NumArray({-2, 0, 3, -5, 2, -1});
        cout << obj->sumRange(0, 2) << " 1" << endl;
        delete obj;
    }

    NumArray() : preSum(_default)
    {
        for (int i = 1, n = preSum.size(); i < n; ++i)
            preSum[i] += preSum[i - 1];
    }

    NumArray(vector<int> &&nums) : preSum(nums)
    {
        for (int i = 1, n = preSum.size(); i < n; ++i)
            preSum[i] += preSum[i - 1];
    }

    int sumRange(int left, int right)
    {
        if (left == 0)
            return preSum[right];
        return preSum[right] - preSum[left - 1];
    }
};