#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int minT;

void dfs(int index, vector<int> &a, vector<int> &b, int time) {
    if (index >= a.size()) {
        minT = min(time, minT); 
        return;
    }
    if (time >= minT)
        return;
    dfs(index + 1, a, b, time + a[index]);
    if (index < b.size())
        dfs(index + 2, a, b, time + b[index]);
}

int fun_dp(vector<int> &a, vector<int> &b) {
    vector<int> dp(a.size() + 1, 0);
    dp[1] = a[0];
    for (int i = 2; i <= a.size(); ++i) {
        dp[i] = min(dp[i-1] + a[i-1], dp[i-2] + b[i-2]);
    }
    return dp[a.size()];
}

int main () {
    int T;
    cin >> T;
    while (T--) {
        int n = 0;
        cin >> n;
        vector<int> a(n, 0);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
        }
        minT = sum;
        vector<int> b(n-1, 0);
        for (int i = 0; i < n-1; i++) {
            cin >> b[i];
        }
        // dfs(0, a, b, 0);
        minT = fun_dp(a, b);
        cout.width(2);
        cout.fill('0');
        cout << (minT/3600 + 8)%12 << ":";
        cout.width(2);
        cout.fill('0');
        cout << ((minT%3600)/60) << ":";
        cout.width(2);
        cout.fill('0');
        cout << ((minT%3600)%60) << " ";
        if ((minT/3600 + 8) > 12) {
            cout << "pm" << endl;
        } else {
            cout << "am" << endl;
        }
    }
    return 0;
}