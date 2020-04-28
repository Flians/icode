#include "../base/icode.h"

class L1143 : public icode {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int i=0,j=0,n1=text1.length(),n2=text2.length();
        if (n1==0 || n2==0)
            return 0;
        vector<vector<int> > dp(n1+1, vector<int>(n2+1, 0));
        for (i=1; i<=n1; ++i) {
            for (j=1; j<=n2; ++j) {
                if (text1[i-1] == text2[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n1][n2];
    }

    void run() {
        cout << longestCommonSubsequence("abcde", "ace") << endl;
    }
};