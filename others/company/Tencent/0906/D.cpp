#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> a(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> index = a;
    sort(index.begin(), index.end());
    int mid = n/2;
    int left = index[mid-1], right = index[mid];
    for (int i = 0; i < n; ++i) {
        if (a[i] >= right) {
            cout << left << endl;
        } else {
            cout << right << endl;
        }
    }
    return 0;
}