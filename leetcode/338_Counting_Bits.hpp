#include "../base/icode.hpp"
class L338 : public icode
{
public:
	void run() {
        // [0,1,1,2,1,2]
        print_res(move(countBits(5)));
    }

    int number_1(int num) {
        int res = 0;
        while (num) {
            num &= num - 1;
            ++res;
        }
        return res;
    }
    
    vector<int> countBits(int num) {
        vector<int> res(num+1, 0);
        for (int i = 1; i <= num; ++i) {
            // res[i] = number_1(i);
            res[i] = res[i&(i-1)] + 1;
        }
        return res;
    }
};