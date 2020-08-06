#include "../base/icode.hpp"
class L342 : public icode
{
public:
	void run() {
        cout << isPowerOfFour(-2147483648) << " false" << endl;
        cout << isPowerOfFour(0) << " false" << endl;
        cout << isPowerOfFour(1) << " true" << endl;
        cout << isPowerOfFour(16) << " true" << endl;
    }

    bool isPowerOfFour(int num) {
        /*
        while (num >= 4) {
            if (num % 4 != 0)
                return false;
            num /= 4;
        }
        return num == 1;
        */
        return num > 0 && !(num & (num - 1)) && !((num-1) % 3);
    }
};