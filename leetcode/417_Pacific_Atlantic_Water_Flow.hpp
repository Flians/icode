#include "../base/icode.hpp"
class L417 : public icode
{
public:
    void run()
    {
        // [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
        print_res(pacificAtlantic({{1, 2, 2, 3, 5}, {3, 2, 3, 4, 4}, {2, 4, 5, 3, 1}, {6, 7, 1, 4, 5}, {5, 1, 1, 2, 4}}));
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>> &&matrix)
    {
        const int n = matrix.size();
        if (n == 0)
            return {};
        const int m = matrix[0].size();
        if (m == 0)
            return {};
        vector<vector<bool>> pacific(n, vector<bool>(m, 0));
        vector<vector<bool>> atlantic(n, vector<bool>(m, 0));
        for (int i = 0; i < n; ++i)
        {
            dfs(matrix, pacific, i, 0);
            dfs(matrix, atlantic, i, m - 1);
        }
        for (int j = 0; j < m; ++j)
        {
            dfs(matrix, pacific, 0, j);
            dfs(matrix, atlantic, n - 1, j);
        }
        vector<vector<int>> res;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (pacific[i][j] && atlantic[i][j])
                {
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }

    void dfs(vector<vector<int>> &matrix, vector<vector<bool>> &vis, int row, int col)
    {
        const int n = matrix.size(), m = matrix[0].size();
        vis[row][col] = 1;
        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for (auto &d : dirs)
        {
            int nx = row + d.first;
            int ny = col + d.second;
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && matrix[nx][ny] >= matrix[row][col])
            {
                dfs(matrix, vis, nx, ny);
            }
        }
    }
};