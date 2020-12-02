#include "../base/icode.hpp"
class L441 : public icode
{
public:
	void run() {
        cout << arrangeCoins(1) << " 1" << endl;
        cout << arrangeCoins(5) << " 2" << endl;
        cout << arrangeCoins(8) << " 3" << endl;
    }

    int arrangeCoins(int n) {
        return floor(sqrt(2.0*n + 0.25) - 0.5);
    }
};