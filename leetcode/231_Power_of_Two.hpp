#include "../base/icode.hpp"
class L231 : public icode
{
public:
	void run() {
        cout << isPowerOfTwo(-2147483648) << " false" << endl;
        cout << isPowerOfTwo(0) << " false" << endl;
        cout << isPowerOfTwo(1) << " true" << endl;
        cout << isPowerOfTwo(2) << " true" << endl;
    }

    bool isPowerOfTwo(int n) {
        /*
        while (n >= 2) {
            if (n % 2 != 0)
                return false;
            n /= 2;
        }
        return n == 1;
        */
        return n > 0 && !(n & (n-1));
    }
};