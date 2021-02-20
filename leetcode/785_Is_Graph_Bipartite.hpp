#include "../base/icode.hpp"
class L785 : public icode
{
public:
    void run()
    {
        cout << isBipartite({{1}, {0, 3}, {3}, {1, 2}}) << " true" << endl;
        cout << isBipartite({{1, 2, 3}, {0, 2}, {0, 1, 3}, {0, 2}}) << " false" << endl;
    }

    bool isBipartite(vector<vector<int>> &&graph)
    {
        size_t n = graph.size();
        vector<int> color(n, 0);
        queue<int> bfs;
        for (size_t i = 0; i < n; ++i)
        {
            if (color[i])
            {
                continue;
            }
            color[i] = 1;
            bfs.push(i);
            while (!bfs.empty())
            {
                int cur = bfs.front();
                bfs.pop();
                for (size_t j = 0, len = graph[cur].size(); j < len; ++j)
                {
                    if (color[graph[cur][j]] == color[cur])
                    {
                        return false;
                    }
                    else if (!color[graph[cur][j]])
                    {
                        color[graph[cur][j]] = -color[cur];
                        bfs.push(graph[cur][j]);
                    }
                }
            }
        }
        return true;
    }
};