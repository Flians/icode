#include "../base/icode.hpp"
class L264 : public icode
{
public:
	void run() {
        cout << nthUglyNumber(10) << " 12" << endl;
        cout << nthUglyNumber(1) << " 1" << endl;
    }

    int nthUglyNumber(int n) {
        vector<int> ugly(n, 0);
        ugly[0] = 1;
        int i = 0, j = 0, k = 0;
        for (int u = 1; u < n; ++u) {
            ugly[u] = min(min(ugly[i]*2, ugly[j]*3), ugly[k]*5);
            if (ugly[u] == ugly[i]*2) ++i;
            if (ugly[u] == ugly[j]*3) ++j;
            if (ugly[u] == ugly[k]*5) ++k;
        }
        return ugly[n-1];
    }
};