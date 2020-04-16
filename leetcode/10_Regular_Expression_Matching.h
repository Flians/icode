#include "../base/icode.h"

class L10 : public icode
{
public:
    enum Result
    {
        UNDEFINE,
        TRUE,
        FALSE
    };

    Result **matches;

    bool dp(int i, int j, string s, string p)
    {
        if (matches[i][j] != UNDEFINE)
            return (matches[i][j] == TRUE);
        bool flag;
        if (j == (int)p.length())
        {
            flag = i == (int)s.length();
        }
        else
        {
            bool first_match = (i < (int)s.length() && (p[j] == s[i] || p[j] == '.'));
            if (j < (int)p.length() - 1 && p[j + 1] == '*')
            {
                flag = (dp(i, j + 2, s, p) || (first_match && dp(i + 1, j, s, p)));
            }
            else
            {
                flag = (first_match && dp(i + 1, j + 1, s, p));
            }
        }
        matches[i][j] = flag ? TRUE : FALSE;
        return flag;
    }

    bool isMatch(string s, string p)
    {
        matches = new Result *[s.length() + 1];
        for (int i = 0; i < (int)s.length() + 1; i++)
        {
            matches[i] = new Result[p.length() + 1]();
        }
        return dp(0, 0, s, p);
    }

    void run()
    {
        cout << "mississippi - mis*is*p*. : " << isMatch("mississippi", "mis*is*p*.") << endl;
        cout << "aa - a : " << isMatch("aa", "a") << endl;
        cout << "aa - a* : " << isMatch("aa", "a*") << endl;
        cout << "ab - .* : " << isMatch("ab", ".*") << endl;
        cout << "aab - c*a*b : " << isMatch("aab", "c*a*b") << endl;
        cout << "ab - .* : " << isMatch("ab", ".*") << endl;
        cout << "b - b.*c : " << isMatch("b", "b.*c") << endl;
        cout << "ab - .*c : " << isMatch("ab", ".*c") << endl;
    }
};