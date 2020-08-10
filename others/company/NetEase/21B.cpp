#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int minD;

void dfs(int index, vector<int> &w, int one, int two, int sum) {
    if (index >= w.size()) {
        if (one == two) {
            minD = min(sum - one - two, minD); 
        }
        return;
    }
    if (max(one, two) > sum/2) {
        return;
    }
    dfs(index + 1, w, one + w[index], two, sum);
    dfs(index + 1, w, one, two + w[index], sum);
    dfs(index + 1, w, one, two, sum);
}

int main () {
    int T;
    cin >> T;
    while (T--) {
        int n = 0;
        cin >> n;
        vector<int> w(n, 0);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> w[i];
            sum += w[i];
        }
        minD = sum;
        dfs(0, w, 0, 0, sum);
        cout << minD << endl;
    }
    return 0;
}