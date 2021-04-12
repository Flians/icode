#include "../base/icode.hpp"
class L667 : public icode
{
public:
    void run()
    {
        // [1, 3, 2]
        print_res(constructArray(3, 2));
    }

    vector<int> constructArray(int n, int k)
    {
        vector<int> ans(n, 0);
        int c = 0;
        for (int v = 1; v < n - k; v++)
        {
            ans[c++] = v;
        }
        for (int i = 0; i <= k; i++)
        {
            ans[c++] = (i % 2 == 0) ? (n - k + i / 2) : (n - i / 2);
        }
        return ans;
    }
};