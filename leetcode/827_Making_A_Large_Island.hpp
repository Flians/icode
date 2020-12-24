#include "../base/icode.hpp"
class L827 : public icode
{
public:
	void run() {
        cout << largestIsland({{0,1},{1,0}}) << " 3" << endl; 
        cout << largestIsland({{0,0},{0,0}}) << " 1" << endl; 
        cout << largestIsland({{1,1},{1,1}}) << " 4" << endl; 
        cout << largestIsland({{1}}) << " 1" << endl; 
    }

    int dfs(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || i >= (int)grid.size() || j < 0 || j >= (int)grid[i].size() || grid[i][j] == 0) {
            return 0;
        }
        grid[i][j] = 0;
        return 1 + dfs(grid, i+1, j) + dfs(grid, i-1, j) + dfs(grid, i, j+1) + dfs(grid, i, j-1);
    }
    int area(vector<vector<int>> grid) {
        int res = 0;
        for (size_t i = 0, row = grid.size(); i < row; ++i) {
            for (size_t j = 0, cow = grid[i].size(); j < cow; ++j) {
                res = max(res, dfs(grid, i,j));
            }
        }
        return res;
    }
    int largestIsland(vector<vector<int>>&& grid) {
        int res = area(grid);
        bool flag = false, has0 = false;
        for (size_t i = 0, row = grid.size(); i < row; ++i) {
            for (size_t j = 0, cow = grid[i].size(); j < cow; ++j) {
                if (grid[i][j] == 0) {
                    has0 = true;
                    if ((i>0?grid[i-1][j]:0) + (i<row-1?grid[i+1][j]:0) + (j>0?grid[i][j-1]:0) + (j<cow-1?grid[i][j+1]:0) >= 2) {
                        grid[i][j] = 1;
                        int tmp = area(grid);
                        if (tmp > res) {
                            flag = true;
                            res = tmp;
                        }
                        grid[i][j] = 0;
                    }
                }
            }
        }
        return flag || !has0  ? res : res + 1;
    }
};