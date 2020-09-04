#include "../base/icode.hpp"
class L459 : public icode
{
public:
	void run() {
        cout << repeatedSubstringPattern("abcabcabcabc") << " true" << endl;
        cout << repeatedSubstringPattern("ababab") << " true" << endl;
        cout << repeatedSubstringPattern("abc") << " false" << endl;
    }

    bool check(string &s, string sub)
    {
        if (s.length() % sub.length() != 0) {
            return false;
        }
        int time = s.length() / sub.length();
        for (int i = 0; i < time; ++i) {
            if (sub != s.substr(i*sub.length(), sub.length()))
                return false;
        }
        return true;
    }
    
    bool repeatedSubstringPattern(string s) {
        int len = s.length()/2;
        while (len > 0) {
            if (check(s, s.substr(0, len))) {
                return true;
            }
            --len;
        }
        return false;
    }
};