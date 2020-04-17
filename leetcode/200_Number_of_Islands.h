#include "../base/icode.h"

class L200 : public icode {
public:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j]=='0')
            return;
        grid[i][j] = '0';
        dfs(grid, i, j+1);
        dfs(grid, i, j-1);
        dfs(grid, i+1, j);
        dfs(grid, i-1, j);
    }
    int numIslands_DFS(vector<vector<char>>& grid) {
        int i=0, j=0, m=grid.size(), n=grid[0].size(), res=0;
        for (i=0; i<m; ++i) {
            for (j=0; j<n; ++j) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    ++res;
                }
            }
        }
        return res;
    }
    
    int numIslands_BFS(vector<vector<char>>& grid) {
        int i=0, j=0, m=grid.size(), n=grid[0].size(), res=0;
        queue<int> record;
        for (i=0; i<m; ++i) {
            for (j=0; j<n; ++j) {
                if (grid[i][j] == '1') {
                    res++;
                    record.push(i*n+j);
                    while (!record.empty()) {
                        int x=record.front()/n, y=record.front()%n;
                        if (x>=0 && x<m && y>=0 && y<n && grid[x][y] == '1') {
                            grid[x][y] = '0';
                            if (y<n-1)
                                record.push(x*n+y+1);
                            if (y>0)
                                record.push(x*n+y-1);
                            record.push((x+1)*n+y);
                            record.push((x-1)*n+y);
                        }
                        record.pop();
                    }
                }
            }
        }
        return res;
    }
    
    
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty())
            return 0;

        // return numIslands_DFS(grid);
        return numIslands_BFS(grid);
    }

    void run() {
        /**
         * [["1","0","0","1","1","1","0","1","1","0","0","0","0","0","0","0","0","0","0","0"],["1","0","0","1","1","0","0","1","0","0","0","1","0","1","0","1","0","0","1","0"],["0","0","0","1","1","1","1","0","1","0","1","1","0","0","0","0","1","0","1","0"],["0","0","0","1","1","0","0","1","0","0","0","1","1","1","0","0","1","0","0","1"],["0","0","0","0","0","0","0","1","1","1","0","0","0","0","0","0","0","0","0","0"],["1","0","0","0","0","1","0","1","0","1","1","0","0","0","0","0","0","1","0","1"],["0","0","0","1","0","0","0","1","0","1","0","1","0","1","0","1","0","1","0","1"],["0","0","0","1","0","1","0","0","1","1","0","1","0","1","1","0","1","1","1","0"],["0","0","0","0","1","0","0","1","1","0","0","0","0","1","0","0","0","1","0","1"],["0","0","1","0","0","1","0","0","0","0","0","1","0","0","1","0","0","0","1","0"],["1","0","0","1","0","0","0","0","0","0","0","1","0","0","1","0","1","0","1","0"],["0","1","0","0","0","1","0","1","0","1","1","0","1","1","1","0","1","1","0","0"],["1","1","0","1","0","0","0","0","1","0","0","0","0","0","0","1","0","0","0","1"],["0","1","0","0","1","1","1","0","0","0","1","1","1","1","1","0","1","0","0","0"],["0","0","1","1","1","0","0","0","1","1","0","0","0","1","0","1","0","0","0","0"],["1","0","0","1","0","1","0","0","0","0","1","0","0","0","1","0","1","0","1","1"],["1","0","1","0","0","0","0","0","0","1","0","0","0","1","0","1","0","0","0","0"],["0","1","1","0","0","0","1","1","1","0","1","0","1","0","1","1","1","1","0","0"],["0","1","0","0","0","0","1","1","0","0","1","0","1","0","0","1","0","0","1","1"],["0","0","0","0","0","0","1","1","1","1","0","1","0","0","0","1","1","0","0","0"]]
         */
    }
};