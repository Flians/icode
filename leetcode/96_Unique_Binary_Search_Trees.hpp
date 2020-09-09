#include "../base/icode.hpp"
class L96 : public icode
{
public:
	void run() {
        cout << numTrees(3) << " 5" << endl;
    }

    int numTrees(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                dp[i] += dp[i-j]*dp[j-1];
            }
        }
        return dp[n];
    }
};