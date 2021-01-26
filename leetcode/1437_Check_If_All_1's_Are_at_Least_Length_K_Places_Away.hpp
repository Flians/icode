#include "../base/icode.hpp"
class L1437 : public icode
{
public:
    void run()
    {
        cout << kLengthApart({1, 0, 0, 1, 0, 1}, 2) << " false" << endl;
        cout << kLengthApart({1, 1, 1, 1, 1}, 0) << " true" << endl;
        cout << kLengthApart({1, 0, 0, 0, 1, 0, 0, 1}, 2) << " true" << endl;
    }

    bool kLengthApart(vector<int> &&nums, int k)
    {
        int last = -1;
        for (int i = 0, len = nums.size(); i < len; ++i)
        {
            if (nums[i])
            {
                if (last != -1 && i - last <= k)
                {
                    return false;
                }
                last = i;
            }
        }
        return true;
    }
};