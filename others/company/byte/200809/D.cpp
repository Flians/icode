#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> A(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    vector<int> B(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> B[i];
    }
    sort(B.begin(), B.end());
    if (A.back() < B.back()) {
        cout << 0 << endl;
        return 0;
    }
    int P;
    cin >> P;
    int i = n-1, j = n-1, res = 1;
    for (; i >= 0; i--) {
        int tmp = j;
        for (; j >= 0; j--) {
            if (B[i] > A[j]) {
                res *= (i-j);
                break;
            }
        }
        if (j == -1) {
            res *= (i-j);
            j = tmp - 1;
        }
    }
    if (i != -1) {
        cout << 0 << endl;
        return 0;
    } else {
        cout << res%P << endl;
    }
    return 0;
}