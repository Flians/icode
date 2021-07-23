#include "../base/icode.hpp"
class L915 : public icode
{
public:
    void run()
    {
        std::cout << partitionDisjoint({1, 1, 1, 0, 6, 12}) << " 4" << std::endl;
    }

    int partitionDisjoint(vector<int> &&nums)
    {
        int l = 0, r = 0, n = nums.size(), lmax = nums[0], rmax = 0;
        while (r < n)
        {
            if (nums[r] < lmax)
            {
                l = r;
                lmax = rmax;
            }
            else
            {
                rmax = max(rmax, nums[r]);
            }
            ++r;
        }
        return l + 1;
    }
};