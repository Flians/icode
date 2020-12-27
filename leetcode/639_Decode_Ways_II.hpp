#include "../base/icode.hpp"
class L639 : public icode
{
public:
	void run() {
        cout << numDecodings("*********") << " 291868912" << endl;
        cout << numDecodings("1*") << " 18" << endl;
    }

    int numDecodings(string s) {
        int last_last = 1, last = s[0] == '*' ? 9 : s[0] == '0' ? 0 : 1;
        int m = 1e9 + 7;
        for (size_t i = 1, len = s.size(); i < len; ++i) {
            int cur = 0;
            if (s[i] != '0') {
                cur += last * (s[i] == '*' ? 9 : 1);
            }
            if (s[i] == '*') {
                if (s[i-1] == '1') {
                    cur += (last_last * 9) % m;
                } else if (s[i-1] == '2') {
                    cur += (last_last * 6) % m;
                } else if (s[i-1] == '*') {
                    cur += (last_last * 15) % m;
                }
            } else {
                if (s[i-1] == '1' || (s[i-1] == '2' && s[i] <= '6')) {
                    cur += last_last;
                } else if (s[i-1] == '*') {
                    cur += last_last * (s[i] <= '6' ? 2 : 1);
                }
            }
            last_last = last;
            last = cur%m;
        }
        return last;
    }
};