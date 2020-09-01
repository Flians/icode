#include <iostream>
#include <vector>
using namespace std;
int fun(vector<int> &all, vector<int> &nums) {
    int res = 0;
    for (auto item : nums) {
        vector<int>::iterator iter = all.begin();
        for (; iter != all.end();) {
            if ((*iter) % item == 0) {
                ++res;
                iter = all.erase(iter);
            } else {
                ++iter;
            }
        }
    }
    return res;
}

int main() {
    int i, n, m;
    cin >> n >> m;
    vector<int> nums(m, 0);
    for (i = 0; i<m; ++i) {
        cin >> nums[i];
    }
    vector<int> all(n, 0);
    for (i = 0; i < n; ++i)
        all[i] = i+1;
    int res = fun(all, nums);
    
    cout << res << endl;
    return 0;
}