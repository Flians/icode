#include "../base/icode.hpp"

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

    
    bool isMatch_dp(string s, string p) {
        int m = s.size(),n = p.size();
        vector<vector<bool>> dp(m+1,vector<bool>(n+1,false));
        dp[0][0] = true;
        for (int j = 1;j < n && p[j] == '*';j+=2)
            dp[0][j+1] = true;
        for (int i = 0;i < m;i++)
            for (int j = 0;j < n;j++){
                if (p[j]!='*')
                    //如果是字母或.只受左上方向影响，即方向3
                    dp[i+1][j+1] = p[j]=='.' ? dp[i][j] : (dp[i][j] && (p[j]==s[i]));
                else
                    //如果是*则受左和上两个方向影响，即方向1和2，有三个或分别对应上述三种情况
                    // p[j - 1] != s[i] 且 p[j - 1] != '.' -> dp[i+1][j-1] *取0
                    // p[j - 1] == s[i] 或 p[j - 1] == '.' -> dp[i + 1][j] || dp[i][j + 1] || dp[i + 1][j - 1] 
                    dp[i+1][j+1] = dp[i+1][j-1] || dp[i+1][j] || (dp[i][j+1]&&((p[j-1]==s[i])||p[j-1]=='.'));
            }
        return dp[m][n];
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