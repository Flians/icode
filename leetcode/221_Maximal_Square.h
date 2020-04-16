#include "../base/icode.h"
class L221 : public icode
{
public:
    int maximalSquare(vector<vector<char> > &matrix)
    {
        if (matrix.empty() || matrix[0].empty())
            return 0;
        int m = matrix.size(), n = matrix[0].size(), res = 0, pre = 0;
        vector<int> dp(m + 1, 0);
        for (int j = 0; j < n; ++j)
        {
            for (int i = 1; i <= m; ++i)
            {
                int t = dp[i];
                if (matrix[i - 1][j] == '1')
                {
                    dp[i] = min(dp[i], min(dp[i - 1], pre)) + 1;
                    res = max(res, dp[i]);
                }
                else
                {
                    dp[i] = 0;
                }
                pre = t;
            }
        }
        return res * res;
    }

    void run()
    {
    }
};