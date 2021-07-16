#include "../base/icode.hpp"
class L611 : public icode
{
public:
    void run()
    {
        std::cout << triangleNumber({2, 2, 3, 4}) << " 3" << std::endl;
    }

    int triangleNumber_bf(vector<int> &&nums)
    {
        std::sort(nums.begin(), nums.end());
        int res = 0, n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                int add = nums[i] + nums[j], sub = abs(nums[i] - nums[j]);
                for (int k = j + 1; k < n; ++k)
                {
                    if (nums[k] < add)
                    {
                        res += nums[k] > sub ? 1 : 0;
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
        return res;
    }

    int triangleNumber(vector<int> &&nums)
    {
        std::sort(nums.begin(), nums.end());
        int res = 0, n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            int k = i + 2;
            for (int j = i + 1; j < n && nums[i] != 0; ++j)
            {
                int add = nums[i] + nums[j];
                while (k < n && add > nums[k])
                {
                    ++k;
                }
                res += k - j - 1;
            }
        }
        return res;
    }
};