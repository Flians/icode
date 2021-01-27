#include "../base/icode.hpp"
class L1680 : public icode
{
public:
    void run()
    {
        cout << concatenatedBinary(12) << " 505379714" << endl;
        cout << concatenatedBinary(3) << " 27" << endl;
    }

    int concatenatedBinary(int n)
    {
        long res = 0, mod = 1e9 + 7;
        for (int i = 1; i <= n; ++i)
        {
            int tmp = i;
            while (tmp)
            {
                tmp >>= 1;
                res <<= 1;
                res %= mod;
            }
            res += i;
            res %= mod;
        }
        return res;
    }
};