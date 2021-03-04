#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int INF = 0x7ff;

std::vector<int> find_min_path(const std::vector<std::vector<int>> &grid, int src, int tar)
{
    std::size_t n = grid.size();
    std::vector<int> parent(n, -1);
    // cur, cost
    std::vector<std::pair<int, int>> record;
    record.emplace_back(src, 0);
    bool found = false;
    while (!record.empty() && !found)
    {
        std::sort(record.begin(), record.end(), [](const std::pair<int, int> &a, const std::pair<int, int> &b) {
            return a.second > b.second;
        });
        std::pair<int, int> cur = record.back();
        record.pop_back();
        if (cur.first == tar)
        {
            return {cur.first};
        }
        auto &cur_next = grid[cur.first];
        for (std::size_t i = 0; i < n; ++i)
        {
            if (cur_next[i] != INF && i != cur.first)
            {
                int cost = cur_next[i] + cur.second;
                std::pair<int, int> *_find = nullptr;
                for (auto &item : record)
                {
                    if (item.first == i)
                    {
                        _find = &item;
                        break;
                    }
                }
                if (_find)
                {
                    if (_find->second > cost)
                    {
                        _find->second = cost;
                        parent[_find->first] = cur.first;
                    }
                }
                else
                {
                    parent[i] = cur.first;
                    if (i == tar)
                    {
                        found = 1;
                        break;
                    }
                    record.emplace_back(i, cost);
                }
            }
        }
    }
    std::vector<int> path;
    while (src != tar)
    {
        path.emplace_back(tar);
        tar = parent[tar];
    }
    path.emplace_back(src);
    std::reverse(path.begin(), path.end());
    return path;
}

int main()
{
    //int a;
    //cin >> a;
    auto path = find_min_path({{0, 12, INF, INF, INF, 16, 14},
                               {12, 0, 10, INF, INF, 7, INF},
                               {INF, 10, 0, 3, 5, 6, INF},
                               {INF, INF, 3, 0, 4, INF, INF},
                               {INF, INF, 5, 4, 0, 2, 8},
                               {16, 7, 6, INF, 2, 0, 9},
                               {14, INF, INF, INF, 8, 9, 0}},
                              3, 0);
    for (auto i : path)
    {
        cout << i << " ";
    }
    cout << endl;
}