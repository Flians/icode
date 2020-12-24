#include "../base/icode.hpp"
class L63 : public icode
{
public:
	void run() {
        cout << uniquePathsWithObstacles({{0,1},{0,0}}) << " 1" << endl;
        cout << uniquePathsWithObstacles({{0,0,0},{0,1,0},{0,0,0}}) << " 2" << endl;
    }

    int uniquePathsWithObstacles(vector<vector<int>>&& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<int> dp(n, 0);
        dp[0] = 1;
        for (int i = 0; i < m; ++i) {
            dp[0] &= obstacleGrid[i][0]==0;
            for (int j = 1; j < n; ++j) {
                if (obstacleGrid[i][j]) {
                    dp[j] = 0;
                } else {
                    dp[j] += dp[j-1];
                }
            }
        }
        return dp[n-1];
    }
};