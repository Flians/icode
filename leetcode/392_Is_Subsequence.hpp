#include "../base/icode.hpp"
class L392 : public icode
{
public:
	void run() {
        cout << isSubsequence("abc", "ahbgdc") << " true" << endl;
        cout << isSubsequence("axc", "ahbgdc") << " false" << endl;
    }

    bool isSubsequence(string s, string t) {
        size_t j = 0;
        for (size_t i = 0; i < t.length(); ++i) {
            if (j == s.length())
                break;
            if (s[j] == t[i])
                ++j;
        }
        return j == s.length();
    }
};