#include "../base/icode.hpp"
class L330 : public icode
{
public:
    void run()
    {
        cout << minPatches({1, 3}, 6) << " 1" << endl;
    }

    int minPatches(vector<int> &&nums, int n)
    {
        long cur = 1, patches = 0, i = 0, ns = nums.size();
        while (cur <= n)
        {
            if (i < ns && nums[i] <= cur)
            {
                cur += nums[i++];
            }
            else
            {
                cur *= 2;
                ++patches;
            }
        }
        return patches;
    }
};