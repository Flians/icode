#include "../base/icode.hpp"
class L594 : public icode
{
public:
    void run()
    {
        cout << findLHS({1, 1, 1, 1}) << " 0" << endl;
        cout << findLHS({1, 3, 2, 2, 5, 2, 3, 7}) << " 5" << endl;
    }

    int findLHS(vector<int> &&nums)
    {
        sort(nums.begin(), nums.end());
        size_t res = 0, start = 0, new_start = 0;
        for (size_t i = 1, n = nums.size(); i < n; ++i)
        {
            if (nums[i] - nums[start] > 1)
                start = new_start;
            if (nums[i] != nums[i - 1])
                new_start = i;
            if (nums[i] - nums[start] == 1)
                res = max(res, i - start + 1);
        }
        return res;
    }
};