#include "../base/icode.hpp"
class L66 : public icode
{
public:
	void run() {
        vector<int> digits = {1,2,3};
        // [1,2,4]
        print_res(plusOne(digits));
        digits = {4,3,2,1};
        // [4,3,2,2]
        print_res(plusOne(digits));
        digits = {0};
        // [1]
        print_res(plusOne(digits));
    }

    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        for (int i = digits.size() - 1; i >= 0 && carry > 0; --i) {
            digits[i] += carry;
            carry = digits[i] / 10;
            digits[i] %= 10;
        }
        if (carry > 0) {
            digits.insert(digits.begin(), carry);
        }
        return digits;
    }
};