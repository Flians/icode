#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#include <string>
#include <iostream>

using namespace std;

typedef long long ll;

const int maxn = 2e6 + 7;

string a[maxn];
int t[maxn][26];
int val[maxn];
int tot;

void insert(string s) {
    int u = 0;
    for(int i = 0;i < s.size();i++) {
        int id = s[i] - 'A';
        if(!t[u][id]) {
            t[u][id] = ++tot;
        }
        val[t[u][id]]++;
        u = t[u][id];
    }
}

int main() {
    int T;scanf("%d",&T);
    int kase = 0;
    while(T--) {
        tot = 0;
        memset(val,0,sizeof(val));
        memset(t,0,sizeof(t));
        int n,k;scanf("%d%d",&n,&k);
        for(int i = 1;i <= n;i++) {
            cin >> a[i];
            insert(a[i]);
        }
        
        int ans = 0;
        for(int i = 1;i <= tot;i++) {
            ans += val[i] / k;
        }
        
        printf("Case #%d: %d\n",++kase,ans);
    }
    return 0;
}
