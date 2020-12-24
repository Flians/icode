#include "../base/icode.hpp"
class L1254 : public icode
{
public:
	void run() {
        cout << closedIsland({{1,1,1,1,1,1,1,0},{1,0,0,0,0,1,1,0},{1,0,1,0,1,1,1,0},{1,0,0,0,0,1,0,1},{1,1,1,1,1,1,1,0}}) << " 2" << endl;
        cout << closedIsland({{0,0,1,0,0},{0,1,0,1,0},{0,1,1,1,0}}) << " 1" << endl;
        cout << closedIsland({{1,1,1,1,1,1,1},
               {1,0,0,0,0,0,1},
               {1,0,1,1,1,0,1},
               {1,0,1,0,1,0,1},
               {1,0,1,1,1,0,1},
               {1,0,0,0,0,0,1},
               {1,1,1,1,1,1,1}}) << " 2" << endl;
    }

    void dfs(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || i >= (int)grid.size() || j < 0 || j >= (int)grid[0].size() || grid[i][j]) return;
        grid[i][j] = 1;
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
    }
    int closedIsland(vector<vector<int>>&& grid) {
        int res = 0, i = 0, j = 0, row = grid.size(), cow = grid[i].size();
        for (; j < cow; ++j) {
            if (grid[i][j] == 0) {
                dfs(grid, i, j);
            }
            if (i == 0 && j == cow -1) {
                j = 0;
                i = row - 1;
            }
        }
        for (j = 0; i >= 0; --i) {
            if (grid[i][j] == 0) {
                dfs(grid, i, j);
            }
            if (i == 0 && j == 0) {
                j = cow - 1;
                i = grid.size() - 1;
            }
        }
        
        for (i = 0; i < row; ++i) {
            for (j = 0; j < cow; ++j) {
                if (grid[i][j] == 0) {
                    ++res;
                    dfs(grid, i, j);
                }
            }
        }
        return res;
    }
};