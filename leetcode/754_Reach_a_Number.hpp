#include "../base/icode.hpp"
class L754 : public icode
{
public:
	void run() {
        cout << reachNumber(3) << " 2" << endl;
        cout << reachNumber(2) << " 3" << endl;
    }

    int reachNumber(int target) {
        target = abs(target);
        int k = 0;
        while (target > 0)
            target -= ++k;
        return target % 2 == 0 ? k : k + 1 + k%2;
    }
};