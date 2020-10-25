#include "../base/icode.hpp"
class L1510 : public icode
{
public:
	void run() {
        cout << winnerSquareGame(1) << " true" << endl;
        cout << winnerSquareGame(2) << " false" << endl;
        cout << winnerSquareGame(4) << " true" << endl;
        cout << winnerSquareGame(17) << " false" << endl;
    }

    bool winnerSquareGame(int n) {
        vector<bool> dp(n+1, 0);
        for (int i = 0; i < n; ++i) {
            if (dp[i]) continue;
            for (int j = 1; i + j*j <= n; ++j) {
                dp[i + j*j] = true;
            }
        }
        return dp[n];
    }
};