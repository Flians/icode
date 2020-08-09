#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int maxL = 1;

void dfs(vector<vector<int>> &data, int index, int cur) {
    if (index >= data.size() - 1) {
        maxL = max(maxL, cur);
        return;
    }
    if (data[index][0] < data[index + 1][0] && data[index][1] < data[index + 1][1])
        dfs(data, index + 1, cur + 1);
    dfs(data, index + 1, cur);
}
/*
5
5 5
3 1
2 6
4 2
1 4
*/
int main() {
    int n;
    cin >> n;
    vector<vector<int>> data(n, vector<int>(2, 0));
    for (int i = 0; i < n; ++i) {
        cin >> data[i][0] >> data[i][1];
    }
    sort(data.begin(), data.end(), [&](vector<int> &a, vector<int> &b){
        return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
    });
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; ++i) {
        dp[i][0] = 1;
        for (int j = 1; j < i; ++j) {
            if (data[i-1][0] > data[j-1][0] && data[i-1][1] > data[j-1][1]) {
                dp[i][j] = max(dp[i][j], dp[j][0] + 1);
                dp[i][0] = max(dp[i][j], dp[i][0]);
            }
        }
    }
    // dfs(data, 0, 0);
    cout << dp[n][0] << endl;
    return 0;
}