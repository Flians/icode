#include "../base/icode.hpp"
class L1277 : public icode
{
public:
	void run() {
        vector<vector<int>> data = {{0,1,1,1}, {1,1,1,1},{0,1,1,1}};
        cout << countSquares(data) << " 15" << endl;
    }

    int countSquares(vector<vector<int>>& matrix) {
        int res = 0;
        if (matrix.empty())
            return res;
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));
        for (size_t i=0; i<matrix.size(); ++i) {
            for (size_t j=0; j<matrix[0].size(); ++j) {
                if (matrix[i][j] == 1) {
                    if (i*j == 0) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j])) + 1;
                    }
                    res += dp[i][j];
                }
            }
        }
        return res;
    }
};