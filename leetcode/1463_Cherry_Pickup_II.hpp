#include "../base/icode.hpp"
class L1463 : public icode
{
public:
	void run() {
        cout << cherryPickup({{1,0,0,0,0,0,1},{2,0,0,0,0,3,0},{2,0,9,0,0,0,0},{0,3,0,5,4,0,0},{1,0,2,3,0,0,6}}) << " 28" << endl;
    }

    int cherryPickup(vector<vector<int>>&& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<int>>> dp(grid.size(), vector<vector<int>>(grid[0].size(), vector<int>(grid[0].size(), 0)));
        for (int i = n-1; i >= 0; --i) {
            for (int j = 0; j < m; ++j) {
                for (int k = 0; k < m; ++k) {
                    dp[i][j][k] = grid[i][j];
                    if (j != k) {
                        dp[i][j][k] += grid[i][k];
                    }
                    if (i < n - 1) {
                        int tmp = 0;
                        for (int r1 = j - 1; r1 <= j + 1; ++r1) {
                            for (int r2 = k - 1; r2 <= k + 1; ++r2) {
                                if (r1 >=0 && r1 < m && r2 >= 0 && r2 < m && tmp < dp[i+1][r1][r2]) {
                                    tmp = dp[i+1][r1][r2];
                                }
                            }
                        }
                        dp[i][j][k] += tmp;
                    }
                }
            }
        }
        return dp[0][0][m-1];
    }
};