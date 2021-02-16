#include "../base/icode.hpp"
class L1337 : public icode
{
public:
    void run()
    {
        // [0,2]
        print_res(kWeakestRows({{1, 0, 0, 0}, {1, 1, 1, 1}, {1, 0, 0, 0}, {1, 0, 0, 0}}, 2));
    }

    vector<int> kWeakestRows(vector<vector<int>> &&mat, int k)
    {
        auto cmp = [&mat](pair<int, int> &a, pair<int, int> &b) {
            return a.first == b.first ? a.second > b.second : a.first > b.first;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> weak(cmp);
        for (size_t i = 0, n = mat.size(); i < n; ++i)
        {
            int item = 0;
            for (auto &j : mat[i])
            {
                item += j;
            }
            weak.emplace(item, i);
        }
        vector<int> res;
        while (k--)
        {
            res.push_back(weak.top().second);
            weak.pop();
        }
        return res;
    }
};