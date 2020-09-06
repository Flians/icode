#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;
int fun(vector<vector<int>> &group, unordered_map<int, vector<int>> &record) {
    unordered_set<int> res;
    vector<bool> vis(group.size(), false);
    queue<int> q;
    for (auto it : record[0]) {
        vis[it] = 1;
        q.push(it);
    }
    while (!q.empty()) {
        for (auto pi : group[q.front()]) {
            res.insert(pi);
            for (auto it : record[pi]) {
                if (!vis[it]) {
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
        q.pop();
    }
    return res.size();
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> group;
    unordered_map<int, vector<int>> record;
    for (int i = 0; i < m; ++i) {
        int num;
        cin >> num;
        vector<int> item(num, 0);
        for (int j = 0; j < num; ++j) {
            cin >> item[j];
            if (record.count(item[j])) {
                record[item[j]].push_back(i);
            } else {
                vector<int> it;
                it.push_back(i);
                record[item[j]] = it;
            }
        }
        group.push_back(item);
    }
    cout << fun(group, record) << endl;
    return 0;
}