#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main () {
    int N;
    cin >> N;
    vector<vector<int>> nums(N+1, vector<int>(N+1, 0));
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            cin >> nums[i][j];
            nums[i][0] += nums[i][j];
            nums[0][j] += nums[i][j];; 
        }
    }

    for (int i = N; i > 1; --i) {
        int m = 1, n = 1, maxS = 0;
        for (; n <= nums.size(); n++) {
            for (m = 1; m <= nums[0].size(); m++) {
                int tmp = nums[n][0] + nums[0][m] - nums[n][m];
                if (tmp > maxS)
                    maxS = tmp;
            }
        }
        cout << n << " " << m << endl;
        // clear cow
        for (int j = 1; j < nums.size(); ++j) {
            nums[j][0] -= nums[j][m];
            nums[0][j] -= nums[n][j];
            nums[j].erase(nums[j].begin() + m);
        }
        // clear row
        nums.erase(nums.begin() + n);
    }
    cout << "1 1" << endl;
    return 0;
}