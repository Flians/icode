#include "../base/icode.hpp"
class L67 : public icode
{
public:
	void run() {
        cout << addBinary("11", "1") << "100" << endl;
    }

    string addBinary(string a, string b) {
        int carry = 0;
        string res = "";
        for (int i = a.size()-1, j = b.size()-1; i >= 0 || j >= 0 || carry > 0; ) {
            if (i >= 0) carry += a[i--] - '0';
            if (j >= 0) carry += b[j--] - '0';
            res += '0' + carry%2;
            carry /= 2;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};