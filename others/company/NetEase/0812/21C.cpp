#include <iostream>
#include <vector>
#include <cmath>
#include <stack>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main () {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        stack<int> order;
        unordered_map<int, pair<int, int>> record;
        for (int i = 0; i < N; ++i) {
            int t,e,s;
            cin >> t >> e >> s;
            if (order.empty()){
                record[e] = {t, 0};
                order.push(e);
            } else if (order.top() != e) {
                if (record.count(e) == 0) {
                    record[e] = {t, 0};
                    record[order.top()].second += t - record[order.top()].first;
                    order.push(e);
                } else
                {
                    record[e].second += t - record[order.top()].first;
                    stack<int> tmp;
                    while (order.top() != e) {
                        tmp.push(order.top());
                        order.pop();
                    }
                    order.pop();
                    while (!tmp.empty()) {
                        order.push(tmp.top());
                        tmp.pop();
                    }
                    record[order.top()].first = t;
                }
            } else {
                record[order.top()].second += t - record[order.top()].first;
                order.pop();
                if (!order.empty())
                    record[order.top()].first = t;
            }
        }
        int maxT = 0, id = -1;
        for (auto item : record) {
            if (maxT < item.second.second) {
                maxT = item.second.second;
                id = item.first;
            }
        }
        cout << id << endl;
    }
    return 0;
}