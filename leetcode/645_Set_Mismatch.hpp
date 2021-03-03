#include "../base/icode.hpp"
class L645 : public icode
{
public:
    void run()
    {
        // [1,2]
        print_res(findErrorNums({1, 1}));
    }

    vector<int> findErrorNums(vector<int> &&nums)
    {
        bool a[10001] = {0};
        vector<int> re(2, 0);
        for (int i : nums)
        {
            if (a[i])
            {
                re[0] = i;
            }
            a[i] = 1;
        }
        for (int i = 1, n = nums.size(); i <= n; ++i)
        {
            if (!a[i])
            {
                re[1] = i;
                break;
            }
        }
        return re;
    }
};