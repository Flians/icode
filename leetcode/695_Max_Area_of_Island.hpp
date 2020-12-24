#include "../base/icode.hpp"
class L695 : public icode
{
public:
	void run() {
        cout << maxAreaOfIsland({{0,0,0,0,0,0,0,0}}) << " 0" << endl;
        cout << maxAreaOfIsland({{0,0,1,0,0,0,0,1,0,0,0,0,0}, {0,0,0,0,0,0,0,1,1,1,0,0,0}, {0,1,1,0,1,0,0,0,0,0,0,0,0}, {0,1,0,0,1,1,0,0,1,0,1,0,0}, {0,1,0,0,1,1,0,0,1,1,1,0,0}, {0,0,0,0,0,0,0,0,0,0,1,0,0}, {0,0,0,0,0,0,0,1,1,1,0,0,0}, {0,0,0,0,0,0,0,1,1,0,0,0,0}}) << " 6" << endl;
    }

    int dfs(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || i >= (int)grid.size() || j < 0 || j >= (int)grid[i].size() || grid[i][j] == 0) {
            return 0;
        }
        grid[i][j] = 0;
        return 1 + dfs(grid, i+1, j) + dfs(grid, i-1, j) + dfs(grid, i, j+1) + dfs(grid, i, j-1);
    }
    
    int maxAreaOfIsland(vector<vector<int>>&& grid) {
        int res = 0;
        for (int i = 0, row = grid.size(); i < row; ++i) {
            for (int j = 0, cow = grid[i].size(); j < cow; ++j) {
                res = max(res, dfs(grid, i, j));
            }
        }
        return res;
    }
};