#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int res = 0;
vector<string> tmp;

void merge(int l, int m, int r, vector<string> &strs) {
    int i = l;
    int j = m + 1;
    int k = l;
    while (i <= m && j <= r) {
        if (strs[i] > strs[j]) {
            tmp[k++] = strs[j++];
            res += m - i + 1;
        } else {
            tmp[k++] = strs[i++];
        }
    }
    while (i <= m) tmp[k++] = strs[i++];
    while (j <= r) tmp[k++] = strs[j++];
    for (i = l; i <= r; ++i) {
        strs[i] = tmp[i];
    }
}

void merge_sort(int l, int r, vector<string> &strs) {
    if (l < r) {
        int m = (l+r)/2;
        merge_sort(l, m, strs);
        merge_sort(m+1, r, strs);
        merge(l, m, r, strs);
    }
}

int main() {
    int n, id;
    cin >> n;
    vector<char> color(2*n);
    for (int i = 0; i < 2*n; ++i) {
        cin >> color[i];
    }
    vector<string> strs(2*n);
    tmp.resize(2*n);
    for (int i = 0; i < 2*n; ++i) {
        cin >> id;
        strs[i] = to_string(id) + color[i];
    }
    merge_sort(0, 2*n-1, strs);
    cout << res << endl;
    for (auto &it : strs) {
        cout << it << " ";
    }
    return 0;
}