#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    vector<string> strs(n);
    unordered_map<string, int> time;
    for (int i = 0; i < n; ++i) {
        cin >> strs[i];
        if (time.count(strs[i])) {
            ++time[strs[i]];
        } else {
            time[strs[i]] = 1;
        }
    }
    sort(strs.begin(), strs.end(), [&](string &a, string &b){
        return time[a] == time[b] ? a < b : time[a] > time[b];
    });
    strs.erase(unique(strs.begin(),strs.end()), strs.end());
    for (int i = 0; i < k; ++i) {
        cout << strs[i] << " " << time[strs[i]] << endl;
    }
    sort(strs.begin(), strs.end(), [&](string &a, string &b){
        return time[a] == time[b] ? a < b : time[a] < time[b];
    });
    for (int i = 0; i < k; ++i) {
        cout << strs[i] << " " << time[strs[i]] << endl;
    }
    return 0;
}