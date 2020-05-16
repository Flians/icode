#include "../base/icode.hpp"
class L367 : public icode {
public:
    // 1 + 3 + 5 + 7 = 16
    bool isPerfectSquare(int num) {
        int i = 1;
        while (num > 0) {
            num -= i;
            i += 2;
            if (num == 0)
                return true;
        }
        return false;
    }

    void run() {
        cout << isPerfectSquare(16) << endl;
    }
};