#include "../base/icode.hpp"
class L60 : public icode
{
public:
	void run() {}

    int factorial(int n)
    {
        if (n < 0 ) return 0;
        return !n ? 1 : n * factorial(n - 1);
    }
    string getPermutation(int n, int k) {
        string res = "";
        for (int i = 1; i <= n; i++)
            res += ('0' + i);
        int pt = 0;
        while (k > 1) {
            int base = factorial(n-pt-1);
            if (k > base) {
                int index = pt + (k-1)/base;
                string tmp = "";
                tmp += res[index];
                res.erase(index, 1);
                res.insert(pt, tmp);
                k = (k-1)%base + 1;
            }
            ++pt;
        }
        return res;
    }
};