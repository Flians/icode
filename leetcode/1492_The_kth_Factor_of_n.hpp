#include "../base/icode.hpp"
class L1492 : public icode
{
public:
	void run() {
        cout << kthFactor(12, 3) << " 3" << endl;
        cout << kthFactor(7, 2) << " 7" << endl;
        cout << kthFactor(4, 4) << " -1" << endl;
        cout << kthFactor(1, 1) << " 1" << endl;
    }

    int kthFactor(int n, int k) {
        if (k < 1 || k > n) {
            return -1;
        }
        for (int i = 1; i <= n; ++i) {
            if (n % i == 0) {
                --k;
            }
            if (k == 0) {
                return i;
            }
        }
        return -1;
    }
};