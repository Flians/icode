#include "../base/icode.hpp"
class L1091 : public icode
{
public:
    void run()
    {
        cout << shortestPathBinaryMatrix({{0, 1}, {1, 0}}) << " 2" << endl;
    }

    int shortestPathBinaryMatrix(vector<vector<int>> &&grid)
    {
        if (grid.empty() || grid[0][0] == 1)
            return -1;
        int res = 0, n = grid.size(), m = grid[0].size();
        queue<pair<int, int>> bfs;
        bfs.emplace(0, 0);
        while (!bfs.empty())
        {
            ++res;
            std::size_t len = bfs.size();
            while (len--)
            {
                auto cur = bfs.front();
                bfs.pop();
                if (cur.first == n - 1 && cur.second == m - 1)
                {
                    return res;
                }
                if (cur.first > 0)
                {
                    if (grid[cur.first - 1][cur.second] == 0)
                    {
                        grid[cur.first - 1][cur.second] = 1;
                        bfs.emplace(cur.first - 1, cur.second);
                    }
                    if (cur.second > 0 && grid[cur.first - 1][cur.second - 1] == 0)
                    {
                        grid[cur.first - 1][cur.second - 1] = 1;
                        bfs.emplace(cur.first - 1, cur.second - 1);
                    }
                    if (cur.second < m - 1 && grid[cur.first - 1][cur.second + 1] == 0)
                    {
                        grid[cur.first - 1][cur.second + 1] = 1;
                        bfs.emplace(cur.first - 1, cur.second + 1);
                    }
                }
                if (cur.first < n - 1)
                {
                    if (grid[cur.first + 1][cur.second] == 0)
                    {
                        grid[cur.first + 1][cur.second] = 1;
                        bfs.emplace(cur.first + 1, cur.second);
                    }
                    if (cur.second > 0 && grid[cur.first + 1][cur.second - 1] == 0)
                    {
                        grid[cur.first + 1][cur.second - 1] = 1;
                        bfs.emplace(cur.first + 1, cur.second - 1);
                    }
                    if (cur.second < m - 1 && grid[cur.first + 1][cur.second + 1] == 0)
                    {
                        grid[cur.first + 1][cur.second + 1] = 1;
                        bfs.emplace(cur.first + 1, cur.second + 1);
                    }
                }
                if (cur.second > 0 && grid[cur.first][cur.second - 1] == 0)
                {
                    grid[cur.first][cur.second - 1] = 1;
                    bfs.emplace(cur.first, cur.second - 1);
                }
                if (cur.second < m - 1 && grid[cur.first][cur.second + 1] == 0)
                {
                    grid[cur.first][cur.second + 1] = 1;
                    bfs.emplace(cur.first, cur.second + 1);
                }
            }
        }
        return -1;
    }
};