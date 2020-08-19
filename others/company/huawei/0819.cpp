#include <iostream>
#include <vector>
using namespace std;

int mod = 1E9 + 7;

int C(int base, int num) {
    int res_p = 1;
    int res_c = 1;
    while (num)
    {
        res_p *= (base--);
        res_c *= (num--);
    }
    return (res_p/res_c)%mod;
}

int main() {
    int N;
    cin >> N;
    vector<int> height(N, 0);
    for (int i = 0; i < N; ++i) {
        int tmp;
        cin >> tmp;
        ++height[tmp];
    }
    int h = 1;
    int res = 1;
    bool flag = false;
    for (int i = 0; i < N; ++i) {
        if (height[i] == 0) {
            flag = true;
        } else {
            if (flag || height[i] > h) {
                res = 0;
                break;
            }
            if (height[i] < h) {
                res *= (C(h, height[i])%mod);
                res %= mod;
            }
        }
        h = height[i] * 2;
    }
    cout << res << endl;
    return 0;
}