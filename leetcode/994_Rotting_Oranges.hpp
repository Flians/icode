#include "../base/icode.hpp"
class L994 : public icode
{
public:
	void run() {
        vector<vector<int>> grid = {{2,1,1},{1,1,0},{0,1,1}};
        cout << orangesRotting(grid) << " 4" << endl;
        grid = {{2,1,1},{0,1,1},{1,0,1}};
        cout << orangesRotting(grid) << " -1" << endl;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int res = 0;
        bool flag = true;
        while (flag) {
            bool tmp = 0;
            bool one = 0;
            for (size_t i = 0; i < grid.size(); ++i) {
                for (size_t j = 0; j < grid[0].size(); ++j) {
                    if (grid[i][j] == 1) {
                        one = 1;
                    } else if (grid[i][j] == 2) {
                        if (i > 0 && grid[i - 1][j] == 1) {
                            grid[i - 1][j] = 2;
                            tmp = 1;
                        }
                        if (i < grid.size() - 1 && grid[i + 1][j] == 1) {
                            grid[i + 1][j] = 3;
                            tmp = 1;
                        }
                        if (j > 0 && grid[i][j - 1] == 1) {
                            grid[i][j - 1] = 2;
                            tmp = 1;
                        }
                        if (j < grid[0].size() - 1 && grid[i][j + 1] == 1) {
                            grid[i][j + 1] = 3;
                            tmp = 1;
                        }
                    } else if (grid[i][j] == 3) {
                        grid[i][j] = 2;
                    }
                }
            }
            if (tmp) {
                ++res;
            } else {
                if (one)
                    res = -1;
                flag = false;
            }
        }
        return res;
    }
};