#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int minN(int n) {
    int i = 2, j = sqrt(n);
    while (i <= j) {
        if (n%i==0) {
            break;
        } else {
            ++i;
        }
    }
    return n==1 ? 1 : (i>j ? n : i);
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        cout << min(minN(N), minN(M)) << endl;
    }
    return 0;
}