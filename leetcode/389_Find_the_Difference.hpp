#include "../base/icode.hpp"
class L389 : public icode
{
public:
	void run() {
        cout << findTheDifference("abcd", "abcde") << " e" << endl;
    }

    char findTheDifference(string s, string t) {
        char r = 0;
        for (char c:s) {
            r ^= c;
        }
        for (char c:t) {
            r ^= c;
        }
        return r;
    }

    char findTheDifference_old(string s, string t) {
        vector<int> time(26, 0);
        for (char c:s) {
            ++time[c-'a'];
        }
        for (char c:t) {
            --time[c-'a'];
        }
        for (int i = 0; i < 26; ++i) {
            if (time[i] == -1) {
                return 'a' + i;
            }
        }
        return 'a';
    }
};