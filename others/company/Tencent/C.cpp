#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(ll n) {
    ll sum = 0;
    while(n) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
int main() {
    int T; scanf("%d", &T); while(T--) {
        ll n; scanf("%lld", &n);
        ll a = 0;
        while(a <= n)a = a * 10 + 9;
        a /= 10;
        cout << solve(a) + solve(n - a) << endl;
    }
    return 0;
}