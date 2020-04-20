#include "../base/icode.h"
class L64 : public icode
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        if (grid.empty())
            return 0;
        int i = 0, j = 0, m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = grid[0][0];
        for (i = 1; i < n; ++i)
        {
            dp[0][i] = dp[0][i - 1] + grid[0][i];
        }
        for (i = 1; i < m; ++i)
        {
            dp[i][0] = grid[i][0] + dp[i - 1][0];
            for (j = 1; j < n; ++j)
            {
                dp[i][j] = min(dp[i][j - 1], dp[i - 1][j]) + grid[i][j];
            }
        }
        return dp[m - 1][n - 1];
    }

    void run() {
        /*
        Input:
        [
        [1,3,1],
        [1,5,1],
        [4,2,1]
        ]
        Output: 7
        */
    }
};