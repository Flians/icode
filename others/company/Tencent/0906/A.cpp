#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7;
int a[N];
int main() {
    int n, m; scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)scanf("%d", &a[i]);
    for(int i = 1; i <= n; i++)if(i != m)printf("%d ", a[i]);
    return 0;
}