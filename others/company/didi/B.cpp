#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

int res = 0;
bool first = 0;
unordered_map<string, bool> record;

void DFS(int index, int n, int m, double sum, string cur) {
    if (index == n) {
        sort(cur.begin(), cur.end());
        if (record.count(cur) == 0 && sum == 1.0) {
            ++res;
            record[cur] = 1;
        }
        return;
    }
    if (index > n)
        return;
    for (int i = 2; i < m; i++) {
        if (first) {
            first = false;
            continue;
        }
        cur.push_back(i+'0');
        DFS(index + 1, n, m, sum + (1.0/i), cur);
        cur.pop_back();
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 2; i < n*n; ++i) {
        DFS(1, n, m, 1.0/i, to_string(i));
    }
    cout << res << endl;
    return 0;
}