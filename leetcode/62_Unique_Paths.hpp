#include "../base/icode.hpp"
class L62 : public icode
{
public:
	void run() {
        cout << uniquePaths(3, 7) << " 28" << endl;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            dp[i][0] = 1;
            for (int j = 1; j < n; ++j) {
                dp[i][j] = dp[i][j-1];
                if (i > 0)  dp[i][j] += dp[i-1][j];
            }
        }
        return dp[m-1][n-1];
    }
};