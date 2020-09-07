#include <iostream>
#include <vector>
#include <deque>
using namespace std;
int dp(int n, int m, deque<int> record) {
    int res = 0;
    if (n == 0) {
        return 1;
    }
    if (n >= m) {
        for (int i = 1; i <= m; ++i) {
            if (!record.empty() && record.front() != i && record.back() != i) {
                record.push_back(i);
                int tmp = record.front();
                record.pop_front();
                res += dp(n - i, m, record);
                record.pop_back();
                record.push_front(tmp);
            }
        }
    } else {
        res += dp(n, n, record);
    }
    return res;
}

int main() {
    int n, m;
    cin >> n >> m;
    if (n < 3) {
        cout << 1 << endl;
    } else if (n == 3 && m == 2) {
        cout << 2 << endl;
    } else if (n == 3 && m > 2) {
        cout << 3 << endl;
    } else {
        deque<int> record;
        record.push_back(-1);
        record.push_back(-1);
        cout << dp(n, m, record) << endl;
    }
    return 0;
}