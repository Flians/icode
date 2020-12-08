#include "../base/icode.hpp"
class L461 : public icode
{
public:
	void run() {
        cout << hammingDistance(1, 4) << " 2" << endl;
    }

    int hammingDistance(int x, int y) {
        x ^= y;
        int res = 0;
        while (x) {
            x &= x-1;
            ++res;
        }
        return res;
    }
};