#include <iostream>
#include <vector>
using namespace std;

long long fun(int l, int r, vector<int> &nums, int minH, int maxH) {
    long long time = 0;
    int wid = r - l + 1;
    if (wid <=0) {
        return time;
    }
    if (wid > minH) {
        time += minH;
        int tminH = maxH;
        int tmaxH = 0;
        bool flag = true;
        for (int i = l; i <= r; ++i) {
            nums[i] -= minH;
            if (nums[i] <= 0) {
                flag = false;
                time += fun(l, i-1, nums, tminH, tmaxH);
            } else {
                if (!flag) {
                    l = i;
                    flag = true;
                    tminH = nums[i];
                    tmaxH = nums[i];
                } else {
                    tminH = min(tminH, nums[i]);
                    tmaxH = max(tmaxH, nums[i]);
                }
            }
        }
    } else {
        time += wid;
    }
    return time;
}

int main()
{
    int n;
    cin >> n;
    int minH = 1E9;
    int maxH = 0;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        minH = min(minH, nums[i]);
        maxH = max(maxH, nums[i]);
    }
    cout << fun(0, n-1, nums, minH, maxH) << endl;
    return 0;
}