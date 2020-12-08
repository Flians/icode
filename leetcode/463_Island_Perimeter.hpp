#include "../base/icode.hpp"
class L463 : public icode
{
public:
	void run() {
        vector<vector<int>> grid = {{0,1,0,0},{1,1,1,0},{0,1,0,0},{1,1,0,0}};
        cout << islandPerimeter(grid) << " 16" << endl;
        grid = {{1}};
        cout << islandPerimeter(grid) << " 4" << endl;
        grid = {{1,0}};
        cout << islandPerimeter(grid) << " 4" << endl;
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int num = 0, connect = 0;
        for (size_t i = 0; i < grid.size(); ++i) {
            for (size_t j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j]) {
                    grid[i][j] = 0;
                    ++num;
                    if (j < grid[i].size() - 1 && grid[i][j + 1]) ++connect;
                    if (i < grid.size() - 1 && grid[i + 1][j]) ++connect;
                }
            }
        }
        return num*4 - connect * 2;
    }
};