#include "../base/icode.hpp"
class L1004 : public icode
{
public:
    void run()
    {
        std::cout << longestOnes({1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0}, 2) << " 6" << endl;
    }

    int longestOnes(vector<int> &&nums, int k)
    {
        size_t left = 0, right = 0, n = nums.size();
        int zero = 0, res = 0;
        for (; right < n; ++right)
        {
            if (!nums[right])
                ++zero;
            while (zero > k)
            {
                if (!nums[left++])
                    --zero;
            }
            res = max((size_t)res, right - left + 1);
        }
        return res;
    }
};