#include "../base/icode.hpp"
class L399 : public icode
{
public:
    void run()
    {
        vector<vector<string>> equations = {{"a", "b"}, {"b", "c"}};
        vector<double> values = {2.0, 3.0};
        vector<vector<string>> queries = {{"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"}};
        print_res(calcEquation(equations, values, queries)); // [6.0, 0.5, -1.0, 1.0, -1.0 ]
    }

    void dfs(double cur, double &res, string src, string tar, unordered_map<string, int> &visited, unordered_map<string, vector<pair<string, double>>> &record)
    {
        if (visited.count(src))
            return;
        visited[src] = 1;
        if (src == tar)
        {
            res = cur;
            return;
        }

        for (auto &item : record[src])
        {
            dfs(cur * item.second, res, item.first, tar, visited, record);
        }
    }

    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {
        unordered_map<string, vector<pair<string, double>>> record;
        for (size_t i = 0; i < equations.size(); ++i)
        {
            /* 0 0 1
            cout << record.size() << " ";
            cout << record[equations[i][0]].size() << " ";
            cout << record.size() << endl;
            */
            record[equations[i][0]].push_back({equations[i][1], values[i]});
            record[equations[i][1]].push_back({equations[i][0], 1.0 / values[i]});
        }
        vector<double> res;
        for (size_t i = 0; i < queries.size(); i++)
        {
            double ans = -1;
            unordered_map<string, int> visited;
            if (record.count(queries[i][0]))
                dfs(1.0, ans, queries[i][0], queries[i][1], visited, record);
            res.push_back(ans);
        }
        return res;
    }
};