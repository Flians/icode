#include "../base/icode.hpp"
class L174 : public icode
{
public:
	void run() {
        vector<vector<int>> dungeon = {{-2,-3,3},{-5,-10,1},{10,30,-5}};
        cout << calculateMinimumHP(dungeon) << " 7" << endl;
        dungeon = {{1,-3,3},{0,-2,0},{-3,-3,-3}};
        cout << calculateMinimumHP(dungeon) << " 3" << endl;
    }

    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        vector<vector<int>> dp (m+1,vector<int>(n+1,INT_MAX));
        dp[m][n-1] = dp[m-1][n] = 1;
        for(int i=m-1;i>=0;--i){
            for(int j=n-1;j>=0;--j){
                dp[i][j] = max(1, min(dp[i+1][j],dp[i][j+1]) - dungeon[i][j]);
            }
        }
        return dp[0][0];
    }

    int calculateMinimumHP_bad(vector<vector<int>>& dungeon) {
        vector<vector<pair<int, int>>> dp(dungeon.size(), vector<pair<int, int>>(dungeon[0].size(), {0,0}));
        if (dungeon[0][0] >= 0) {
            dp[0][0] = {1 + dungeon[0][0], 1};
        } else {
            dp[0][0] = {1, 1 - dungeon[0][0]};
        }
        for (size_t j = 1; j < dungeon[0].size(); ++j) {
            int fl = dp[0][j-1].first + dungeon[0][j];
            int sl = dp[0][j-1].second;
            if (fl <= 0) {
                sl = sl - fl + 1;
                fl = 1;
            }
            dp[0][j] = {fl, sl};
        }
        for (size_t i = 1; i < dungeon.size(); ++i) {
            int fu = dp[i-1][0].first + dungeon[i][0];
            int su = dp[i-1][0].second;
            if (fu <= 0) {
                su = su - fu + 1;
                fu = 1;
            }
            dp[i][0] = {fu, su};
            for (size_t j = 1; j < dungeon[0].size(); ++j) {
                int fl = dp[i][j-1].first + dungeon[i][j];
                int sl = dp[i][j-1].second;
                if (fl <= 0) {
                    sl = sl - fl + 1;
                    fl = 1;
                }

                int fu = dp[i-1][j].first + dungeon[i][j];
                int su = dp[i-1][j].second;
                if (fu <= 0) {
                    su = su - fu + 1;
                    fu = 1;
                }
                if (sl < su) {
                    dp[i][j] = {fl, sl};
                } else if (sl == su) {
                    dp[i][j] = {max(fl, fu), sl};
                } else {
                    dp[i][j] = {fu, su};
                }
            }
        }
        return dp[dungeon.size()-1][dungeon[0].size()-1].second;
    }
};