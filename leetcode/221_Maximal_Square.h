#include "../base/icode.h"
class L221 : public icode
{
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty())
            return 0;
        int i=0,j=0,m=matrix.size(),n=matrix[0].size(), res=0;
        vector<vector<int> > dp(m+1, vector<int>(n+1,0));
        for (i=1; i<=m; ++i) {
            for (j=1; j<=n; ++j) {
                if (matrix[i-1][j-1]=='1') {
                    dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]),dp[i-1][j-1]) + 1;
                    res = max(res, dp[i][j]);
                }
            }
        }
        return res*res;
    }

    int maximalSquare_best(vector<vector<char> > &matrix)
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
        vector<vector<char> > nums = {{'1','0','1','0'},{'1','0','1','1'},{'1','0','1','1'},{'1','1','1','1'}};
        cout << maximalSquare_best(nums) << endl;
    }
};