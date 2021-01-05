#include "../base/icode.hpp"
class L69 : public icode
{
public:
	void run() {
        cout << mySqrt(2147483647) << " 46340" << endl;
    }

    int mySqrt(int x) {
        long i = 1;
        for (int len = x/2; i <= len; ++i) {
            if (i*i >= x) {
                break;
            }
        }
        return i*i == x ? i : i - 1;
    }
};