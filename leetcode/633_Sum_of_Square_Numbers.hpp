#include "../base/icode.hpp"
class L633 : public icode
{
public:
	void run() {
        cout << judgeSquareSum(5) << " true" << endl;
    }

    bool judgeSquareSum(int c) {
        int n = sqrt(c), i = -1;
        while ((i++) < n) {
            int j = sqrt(c - i*i);
            if (i*i + j*j == c) return true;
        }
        return false;
    }
};