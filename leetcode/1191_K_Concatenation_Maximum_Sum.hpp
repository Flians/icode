#include "../base/icode.hpp"
class L1191 : public icode
{
public:
	void run() {
        vector<int> nums = {1,-2,1};
        cout << kConcatenationMaxSum(nums, 5) << " 2" << endl;
        nums = {-1, -2};
        cout << kConcatenationMaxSum(nums, 7) << " 0" << endl;
        nums = {1,2};
        cout << kConcatenationMaxSum(nums, 3) << " 9" << endl;
        cout << kConcatenationMaxSum(nums, 1) << " 3" << endl;
    }

    int kConcatenationMaxSum(vector<int>& arr, int k) {
        long long pre = arr[0], last = arr.back();
        long long maxp = pre, maxl = last;
        long long sum = pre, maxn = pre;
        int i = 1, j = arr.size()-2;
        long long mod = 1E9 + 7;
        while (i < (int)arr.size()) {
            if (sum > 0) {
                sum += arr[i];
            } else {
                sum = arr[i];
            }
            maxn = max(maxn, sum);

            pre += arr[i++];
            maxp = max(maxp, pre);
            last += arr[j--];
            maxl = max(maxl, last);
        }
        if (k == 1) {
            return maxn;
        }
        long long item = maxp + maxl;
        return max(0LL, max(maxn, max(item, item + (k-2)*pre))) % mod;
    }
};