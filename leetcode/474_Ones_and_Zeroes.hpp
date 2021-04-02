#include "../base/icode.hpp"
class L474 : public icode
{
public:
    void run()
    {
        std::cout << findMaxForm({"10", "0001", "111001", "1", "0"}, 5, 3) << " 4" << std::endl;
    }

    int dfs(std::size_t index, std::size_t len, int m, int n, std::vector<std::pair<int, int>> &counter, std::vector<std::vector<std::vector<int>>> &dp)
    {
        if (index == len)
            return 0;
        if (dp[index][m][n] != -1)
            return dp[index][m][n];

        int cur0 = counter[index].first;
        int cur1 = counter[index].second;

        // exclude this idx
        if (m - cur0 < 0 or n - cur1 < 0)
            return dfs(index + 1, len, m, n, counter, dp);

        // satisfy + include/exclude this idx
        int incl = 1 + dfs(index + 1, len, m - cur0, n - cur1, counter, dp);
        int excl = dfs(index + 1, len, m, n, counter, dp);

        return dp[index][m][n] = max(incl, excl);
    }

    int findMaxForm(vector<string> &&strs, int m, int n)
    {
        std::size_t len = strs.size();
        std::vector<std::pair<int, int>> counter(len);
        std::vector<std::vector<std::vector<int>>> dp(len, std::vector<std::vector<int>>(m + 1, std::vector<int>(n + 1, -1)));
        for (std::size_t i = 0; i < len; ++i)
        {
            int _m = 0, _n = 0;
            for (char c : strs[i])
            {
                if (c == '0')
                    ++_m;
                if (c == '1')
                    ++_n;
            }
            counter[i] = {_m, _n};
        }
        return dfs(0, len, m, n, counter, dp);
    }
};