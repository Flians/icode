#include "../base/icode.hpp"
class L980 : public icode
{
public:
	void run() {
        vector<vector<int>> grid = {{1,0,0,0},{0,0,0,0},{0,0,2,-1}};
        cout << uniquePathsIII(grid) << " 2" << endl;
        grid = {{0,1},{2,0}};
        cout << uniquePathsIII(grid) << " 0" << endl;
    }

    void dfs (size_t r, size_t c, int step, int &numP, vector<vector<int>>& grid) {
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] == -1) {
            return;
        }
        if (grid[r][c] == 2) {
            if (step == -1)
                ++numP;
            return;
        }
        grid[r][c] = -1;
        dfs(r + 1, c, step-1, numP, grid);
        dfs(r - 1, c, step-1, numP, grid);
        dfs(r, c + 1, step-1, numP, grid);
        dfs(r, c - 1, step-1, numP, grid);
        grid[r][c] = 0;

    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int step = 0;
        size_t r, c;
        for (size_t i = 0; i < grid.size(); ++i) {
            for (size_t j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    r = i;
                    c = j;
                }
                if (grid[i][j] == 0) {
                    ++step;
                }
            }
        }
        int res = 0;
        dfs(r, c, step, res, grid);
        return res;
    }
};