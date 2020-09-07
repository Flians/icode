/*
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int res = 0;
vector<string> tmp;

void merge(int l, int m, int r, vector<string> &strs) {
    int i = l;
    int j = m + 1;
    int k = l;
    while (i <= m && j <= r) {
        if (strs[i] > strs[j]) {
            tmp[k++] = strs[j++];
            res += m - i + 1;
        } else {
            tmp[k++] = strs[i++];
        }
    }
    while (i <= m) tmp[k++] = strs[i++];
    while (j <= r) tmp[k++] = strs[j++];
    for (i = l; i <= r; ++i) {
        strs[i] = tmp[i];
    }
}

void merge_sort(int l, int r, vector<string> &strs) {
    if (l < r) {
        int m = (l+r)/2;
        merge_sort(l, m, strs);
        merge_sort(m+1, r, strs);
        merge(l, m, r, strs);
    }
}

int main() {
    int n, id;
    cin >> n;
    vector<char> color(2*n);
    for (int i = 0; i < 2*n; ++i) {
        cin >> color[i];
    }
    vector<string> strs(2*n);
    tmp.resize(2*n);
    for (int i = 0; i < 2*n; ++i) {
        cin >> id;
        strs[i] = to_string(id) + color[i];
    }
    merge_sort(0, 2*n-1, strs);
    cout << res << endl;
    for (auto &it : strs) {
        cout << it << " ";
    }
    return 0;
}
*/

/*
考虑dp[i][j]dp[i][j]为第i个黑球，第j个红球按顺序的最小操作次数，那么转移就是dp[i][j]=min(dp[i−1][j]+B(i,j),dp[i][j−1]+W(i,j))dp[i][j]=min(dp[i−1][j]+B(i,j),dp[i][j−1]+W(i,j))
B(i,j)B(i,j)为i号黑球前，有几个比i号黑球大，比j号红球大的球。
W(i,j)W(i,j)为i号红球前，有几个比i号黑球大，比j号红球大的球。
*/
#include <bits/stdc++.h>
#define ll long long
#define maxn 4005
#define inf 1e9
#define pb push_back
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

inline int read()
{
    int x = 0, w = 1;
    char c = getchar();
    while (c < '0' || c > '9')
    {
        if (c == '-')
            w = -1;
        c = getchar();
    }
    while (c <= '9' && c >= '0')
    {
        x = (x << 1) + (x << 3) + c - '0';
        c = getchar();
    }
    return w == 1 ? x : -x;
}

int c1[maxn], c2[maxn], B[maxn][maxn], W[maxn][maxn], n, x[maxn];
int x1[maxn], x2[maxn], cnt1, cnt2, dp[maxn][maxn];
char s[maxn], q;

inline void a1(int x, int val)
{
    for (int i = x; i <= n; i += i & -i)
        c1[i] += val;
}
inline void a2(int x, int val)
{
    for (int i = x; i <= n; i += i & -i)
        c2[i] += val;
}
inline int q1(int x)
{
    int res = 0;
    for (int i = x; i; i -= i & -i)
        res += c1[i];
    return res;
}
inline int q2(int x)
{
    int res = 0;
    for (int i = x; i; i -= i & -i)
        res += c2[i];
    return res;
}

int main()
{
    n = read();
    rep(i, 1, 2 * n) cin >> s[i], x[i] = read();
    rep(i, 1, 2 * n)
    {
        if (s[i] == 'B')
        {
            a1(x[i], 1);
            rep(j, 0, n) B[x[i]][j] = i - q1(x[i]) - q2(j);
        }
        else
        {
            a2(x[i], 1);
            rep(j, 0, n) W[j][x[i]] = i - q1(j) - q2(x[i]);
        }
    }
    rep(i, 0, n) rep(j, 0, n) dp[i][j] = inf;
    dp[0][0] = 0;
    rep(i, 0, n) rep(j, 0, n)
    {
        if (i != 0)
            dp[i][j] = min(dp[i][j], dp[i - 1][j] + B[i][j]);
        if (j != 0)
            dp[i][j] = min(dp[i][j], dp[i][j - 1] + W[i][j]);
    }
    cout << dp[n][n] << endl;
    return 0;
}