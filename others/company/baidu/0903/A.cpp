#include <iostream>
#include <vector>
using namespace std;
int main() {
    int T;
    cin >> T;
    while(T--) {
        int L, n;
        cin >> L >> n;
        vector<int> nums(L, 0);
        while (n--) {
            int l,r;
            cin >> l >> r;
            for (int i = l-1; i < r; ++i)
                ++nums[i];
        }
        cout << nums[0];
        for (int i = 1; i < L; ++i) {
            cout << " " << nums[i];
        }
        cout << endl;
    }
    return 0;
}