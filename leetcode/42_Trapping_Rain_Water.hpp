#include "../base/icode.hpp"
class L42 : public icode
{
public:
    void run()
    {
        cout << trap({0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}) << " 6\n";
    }

    int trap_dp(vector<int> &height)
    {
        if (height.empty())
            return 0;
        int i = 0, temp = 0, sum = 0, n = height.size();
        vector<int> l(n), r(n);

        for (; i < n; i++)
        {
            temp = max(temp, height[i]);
            l[i] = temp;
        }
        temp = 0;
        for (i = n - 1; i >= 0; i--)
        {
            temp = max(temp, height[i]);
            r[i] = temp;
        }
        for (i = 0; i < n; i++)
        {
            sum += min(l[i], r[i]) - height[i];
        }
        return sum;
    }

    int trap(vector<int> &&height)
    {
        int l = 0, r = height.size() - 1;
        int res = 0, lmax = 0, rmax = 0;
        while (l < r)
        {
            if (height[l] < height[r])
            {
                if (height[l] >= lmax)
                {
                    lmax = height[l++];
                }
                else
                {
                    res += lmax - height[l++];
                }
            }
            else
            {
                if (height[r] >= rmax)
                {
                    rmax = height[r--];
                }
                else
                {
                    res += rmax - height[r--];
                }
            }
        }
        return res;
    }
};
