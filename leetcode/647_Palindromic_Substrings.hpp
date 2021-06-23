#include "../base/icode.hpp"
class L647 : public icode
{
public:
    void run()
    {
        cout << countSubstrings("abc") << " 3" << endl;
        cout << countSubstrings("aaa") << " 6" << endl;
    }

    bool check(std::string &s, int beg, int end)
    {
        while (end > beg)
        {
            if (s[beg++] != s[end--])
                return false;
        }
        return true;
    }

    int countSubstrings_bf(string s)
    {
        std::size_t n = s.size();
        int res = n;
        for (std::size_t i = 2; i <= n; ++i)
        {
            for (std::size_t j = 0, m = n - i; j <= m; ++j)
            {
                if (check(s, j, j + i - 1))
                    ++res;
            }
        }
        return res;
    }

    int countSubstrings_dp(string s)
    {
        std::size_t n = s.size();
        int res = n;
        bool dp[n][n];
        fill_n(*dp, n * n, false);
        dp[n - 1][n - 1] = true;
        for (std::size_t i = 0; i < n - 1; ++i)
        {
            dp[i][i] = true;
            dp[i][i + 1] = (s[i] == s[i + 1]);
            res += dp[i][i + 1];
        }
        for (std::size_t i = 2; i <= n; ++i)
        {
            for (std::size_t j = 0, m = n - i; j < m; ++j)
            {
                dp[j][j + i] = dp[j + 1][j + i - 1] && (s[j] == s[j + i]);
                res += dp[j][j + i];
            }
        }
        return res;
    }

    int countPalindromesAroundCenter(const string &s, int beg, int end)
    {
        int res = 0, n = s.size();
        while (beg >= 0 && end < n)
        {
            if (s[beg--] != s[end++])
                break;
            res++;
        }
        return res;
    }

    int countSubstrings(string s)
    {
        int res = 0;
        std::size_t n = s.size();
        for (std::size_t i = 0; i < n; ++i)
        {
            res += countPalindromesAroundCenter(s, i, i);
            res += countPalindromesAroundCenter(s, i, i + 1);
        }
        return res;
    }
};