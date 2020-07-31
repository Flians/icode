#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int T;
    cin >> T;
    while (T--) {
        int num;
        cin >> num;
        vector<int> pi(num ,0);
        for (int i = 0; i < num; ++i) {
            cin >> pi[i];
        }
        sort(pi.begin(), pi.end());
        int sum = 0;
        int len = pi.size() - 2;
        for (int i = 0; i < len; ++i) {
            sum += pi[i] * (len - i) * (len - i + 1) / 2;
        }
        cout << "\n" << sum << endl;
    }
    return 0;
}