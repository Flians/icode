#include<bits/stdc++.h>
using namespace std;

const int N = 5e3 + 7;
int dp[N][N];
int a[N];
int main() {
    memset(dp, 0x3f, sizeof dp);
    dp[0][0] = 0;
    int n; scanf("%d", &n);
    for(int i = 1; i <= n; i++)scanf("%d", &a[i]);
    for(int i = 0; i < n; i++)for(int j = 0; j <= n; j++) {
        int high;
        //竖着刷
        high = min(j, a[i + 1]);
        dp[i + 1][high] = min(dp[i + 1][high], dp[i][j] + 1);
        //横着刷
        if(a[i + 1] < n) {
            if(j >= a[i + 1])dp[i + 1][a[i + 1]] = min(dp[i + 1][a[i + 1]], dp[i][j]);
            else dp[i + 1][a[i + 1]] = min(dp[i + 1][a[i + 1]], dp[i][j] + a[i + 1] - j);
        }
    }
    int ans = n;
    for(int i = 0; i <= n; i++)ans = min(dp[n][i], ans);
    printf("%d\n", ans);
    return 0;
}