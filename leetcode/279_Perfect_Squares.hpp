#include "../base/icode.hpp"
class L279 : public icode
{
public:
	void run() {
        cout << numSquares(12) << " 3" << endl;
        cout << numSquares(13) << " 2" << endl;
    }

    int numSquares(int n) {
        vector<int> dp(n+1, n);
        dp[0] = 0;
        for (int i = 1; i <=n; ++i) {
            for (int j = 1; j*j <= i; ++j) {
                dp[i] = min(dp[i], dp[i-j*j] + 1);
            }
        }
        return dp[n] > n ? -1 : dp[n];
    }
};