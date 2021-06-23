#include "../base/icode.hpp"
class L797 : public icode
{
public:
    void run()
    {
        // [[0,4],[0,3,4],[0,1,3,4],[0,1,2,3,4],[0,1,4]]
        print_res(allPathsSourceTarget({{4, 3, 1}, {3, 2, 4}, {3}, {4}, {}}));
    }

    void dfs(vector<vector<int>> &graph, int n, int index, vector<int> item, vector<vector<int>> &results)
    {
        if (index == n - 1)
        {
            results.emplace_back(item);
        }
        for (int next : graph[index])
        {
            item.push_back(next);
            dfs(graph, n, next, item, results);
            item.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &&graph)
    {
        vector<int> item;
        vector<vector<int>> results;
        item.push_back(0);
        dfs(graph, graph.size(), 0, item, results);
        return results;
    }
};