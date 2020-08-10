#include "../base/icode.hpp"
class L171 : public icode
{
public:
	void run() {
        cout << titleToNumber("A") << " 1" << endl;
        cout << titleToNumber("AB") << " 28" << endl;
    }

    int titleToNumber(string s) {
        int res = 0;
        for (size_t i = 0; i < s.length(); ++i) {
            res = (s[i] - 'A' + 1) + res * 26;
        }
        return res;
    }
};