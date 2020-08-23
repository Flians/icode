#include <iostream>
#include <vector>
#include <unordered_map>
#include <limits.h>
using namespace std;

long long cal_cost(int n, vector<int> &cost) {
    unordered_map<int, long long> dp;
    int last = 0;
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1] + cost[3];
        if (i % 3 == 0) {
            dp[i] = min(dp[i], dp[i/3] + cost[0]);
        }
        if (i % 2 == 0) {
            dp[i] = min(dp[i], dp[i/2] + cost[1]);
        }
        if ((i+1) % 2 == 0) {
            dp[i] = min(dp[i], dp[(i+1)/2] + cost[1] + cost[2]);
        }
        if ((i+1) % 3 == 0) {
            dp[i] = min(dp[i], dp[(i+1)/3] + cost[0] + cost[2]);
        }
        for (int j = last; j < i/3; ++j) {
            dp.erase(j);
        }
        last = i/3;
    }
    return dp[n];
}

void dfs(int index, int n, vector<int> &cost, int cur, int &min_cost) {
    if (index == n) {
        min_cost = min(cur, min_cost);
        return;
    }
    if (cur > min_cost || index <= 0 || index > n) {
        return;
    }
    dfs(index * 3, n, cost, cur + cost[0], min_cost);
    dfs(index * 2, n, cost, cur + cost[1], min_cost);
    dfs(index - 1, n, cost, cur + cost[2], min_cost);
    dfs(index + 1, n, cost, cur + cost[3], min_cost);
}

int main() {
    int C;
    cin >> C;
    while (C--) {
        int n;
        cin >> n;
        vector<int> cost(4, 0);
        for (int i = 0; i < 4; i++) {
            cin >> cost[i];
        }
        /*
        int min_cost = n * cost[3];
        dfs(1, n, cost, cost[3], min_cost);
        cout << min_cost << endl;
        */
        cout << cal_cost(n, cost) << endl;
    }
    return 0;
}