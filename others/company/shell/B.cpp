#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int numL(int i) {
    return floor(log2(i)) + 1;
}

int main() {
    int i, n;
    cin >> n;
    int maxO = 0;
    vector<int> A(n, 0);
    for (i = 0; i < n; ++i) {
        cin >> A[i];
        maxO |= A[i];
    }
    sort(A.begin(), A.end(), greater<int>());
    int minL = n;
    int len = numL(A[i]);
    for(i = 0; i < n; ++i) {
        if (numL(A[i]) < len) {
            break;
        }
        int tmp = A[i];
        for(int j = i; j < n; ++j) {
            tmp |= A[j];
            if (tmp == maxO) {
                minL = min(minL, j-i+1);
                break;
            }
        }
    }
    cout << minL << endl;
    return 0;
}