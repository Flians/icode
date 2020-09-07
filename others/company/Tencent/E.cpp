#include<bits/stdc++.h>
using namespace std;
const int N = 400 + 7;
char str[N];
int dp[N][N];
int main() {
    memset(dp, 0x3f, sizeof dp);
    scanf("%s", str + 1);
    int n = strlen(str + 1);
    for(int i = 1; i <= n; i++) {
        int l = i, r = i;
        while(1) {
            dp[l][r] = 1;
            l--, r++;
            if(l <= 0 || r > n)break;
            if(str[l] != str[r])break;
        }
    }
    for(int i = 1; i < n; i++) {
        int l = i, r = i + 1;
        if(str[l] != str[r])continue;
        while(1) {
            dp[l][r] = 1;
            l--, r++;
            if(l <= 0 || r > n)break;
            if(str[l] != str[r])break;
        }
    }
    for(int len = 1; len < n; len++)for(int i = 1; i <= n - len; i++) {
        int l = i, r = i + len; 
        for(int j = l; j < r; j++)dp[l][r] = min(dp[l][r], dp[l][j] + dp[j + 1][r]);
    }
    int q; scanf("%d", &q); while(q--) {
        int l, r; scanf("%d%d", &l, &r);
        printf("%d\n", dp[l][r]);
    }
    return 0;
}