#include "../base/icode.hpp"
class L1035 : public icode
{
public:    
	void run() {
        vector<int> A = {2,5,1,2,5}, B = {10,5,2,1,5,2};
        cout << maxUncrossedLines(A, B) << " 3" << endl;
    }

    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        vector<vector<int> > dp(A.size() + 1, vector<int>(B.size() + 1, 0));
        for (size_t i = 1; i <= A.size(); ++i) {
            for (size_t j = 1; j <= B.size(); ++j) {
                dp[i][j] = max(dp[i-1][j-1] + (A[i-1] == B[j-1]?1:0), max(dp[i][j-1], dp[i-1][j]));
            }
        }
        return dp[A.size()][B.size()];
    }
};