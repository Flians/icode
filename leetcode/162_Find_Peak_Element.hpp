#include "../base/icode.hpp"
class L162 : public icode
{
public:
    void run()
    {
        std::cout << findPeakElement({1, 2, 3, 1}) << " 2" << std::endl;
    }

    int findPeakElement(vector<int> &&nums)
    {
        int l = 0, r = nums.size() - 1;
        while (l < r)
        {
            int mid = (l + r) / 2;
            if (nums[mid] > nums[mid + 1])
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        return l;
    }
};