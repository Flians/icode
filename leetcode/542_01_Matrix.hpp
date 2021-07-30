#include "../base/icode.hpp"
class L542 : public icode {
public:
    void run() {
        vector<int> nums = {1,1,2,3,3,4,4,8,8};
        print_res(updateMatrix({{0,0,0}, {0,1,0},{1,1,1}}));
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>&& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> dis(n, vector<int>(m, 1e5));
        if (mat[0][0] == 0) dis[0][0] = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i > 0) {
                    dis[i][j] = mat[i][j] == 0 ? 0 : min(dis[i][j], dis[i-1][j] + 1);
                }
                if (j > 0) {
                    dis[i][j] = mat[i][j] == 0 ? 0 : min(dis[i][j], dis[i][j-1] + 1);
                }
            }
        }
        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                if (i < n - 1) {
                    dis[i][j] = mat[i][j] == 0 ? 0 : min(dis[i][j], dis[i+1][j] + 1);
                }
                if (j < m - 1) {
                    dis[i][j] = mat[i][j] == 0 ? 0 : min(dis[i][j], dis[i][j+1] + 1);
                }
            }
        }
        return dis;
     }
};