#include "../base/icode.hpp"
class L72 : public icode
{
public:
	void run() {
        cout << minDistance("", "a") << " 1" << endl;
        cout << minDistance("eat", "sea") << " 2" << endl;
    }

    int minDistance(string word1, string word2) {
        vector<vector<int> > dp(word1.length() + 1, vector<int>(word2.length()+1, 0));
        for (size_t j = 1; j <= word2.length(); ++j) {
            dp[0][j] = j;
        }
        for (size_t i = 1; i <= word1.length(); ++i) {
            dp[i][0] = i;
            for (size_t j = 1; j <= word2.length(); ++j) {
                dp[i][j] = min(((word1[i-1] == word2[j-1])?0:1) + dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j]) + 1);
            }
        }
        return dp[word1.length()][word2.length()];
    }
};