#include "../base/icode.hpp"
class L91 : public icode
{
public:
	void run() {
        cout << numDecodings("2260") << " 0" << endl;
        cout << numDecodings("10") << " 1" << endl;
        cout << numDecodings("2101") << " 1" << endl;
        cout << numDecodings("12345") << " 3" << endl;
    }

    int numDecodings(string s) {
        int last_last = 1, last = s[0]=='0' ? 0 : 1;
        for (size_t i = 1, len = s.size(); i < len; ++i) {
            int cur = 0;
            if (s[i] != '0') {
                cur += last;
            }
            if (s[i-1] == '1' || (s[i-1] == '2' && s[i] <= '6')) {
                cur += last_last;
            }
            last_last = last;
            last = cur;
        }
        return last;
    }
};