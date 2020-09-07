#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

bool check(vector<pair<int, int>> &nums, vector<pair<int, int>> &role, int len) {
    for (int i = 0; i < len; ++i) {
        if (nums[i].first > role[role.size() - len + i].first){
            return false;
        }
    }
    return true;
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        int n, m;
        cin >> n >> m;
        vector<pair<int, int>> nums(n, {0,0});
        for (int i = 0; i < n; ++i) {
            cin >> nums[i].first;
            nums[i].second = i;
        }
        sort(nums.begin(), nums.end());
        vector<pair<int, int>> role(m, {0,0});
        for (int i = 0; i < m; ++i) {
            cin >> role[i].first;
            role[i].second = i;
        }
        sort(role.begin(), role.end());
        int maxL = min(n, m);
        vector<int> res(n, -1);
        while (maxL > 0) {
            if (check(nums, role, maxL)) {
                for (int i = 0; i < maxL; ++i) {
                    res[nums[i].second] = role[role.size() - maxL + i].second + 1;
                }
                break;
            }
            --maxL;
        }
        cout << res[0];
        for (int i = 1; i < n; ++i) {
            cout << " " << res[i];
        }
        cout << endl;
    }
    return 0;
}