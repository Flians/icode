#include "../base/icode.hpp"
class L153 : public icode
{
public:
    void run()
    {
        cout << findMin({2, 1}) << " 1" << endl;
        cout << findMin({4, 5, 6, 7, 0, 1, 2}) << " 0" << endl;
    }

    int findMin(vector<int> &&nums)
    {
        int l = 0, r = nums.size() - 1;
        while (l < r)
        {
            int m = (l + r) / 2;
            if (nums[l] < nums[r])
            {
                return nums[l];
            }
            else
            {
                if (nums[m] >= nums[l])
                {
                    l = m + 1;
                }
                else
                {
                    r = m;
                }
            }
        }
        return nums[l];
    }
};