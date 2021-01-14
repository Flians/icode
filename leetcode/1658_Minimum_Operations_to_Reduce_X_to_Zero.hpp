#include "../base/icode.hpp"
class L1658 : public icode
{
public:
	void run() {
        cout << minOperations({1,1,4,2,3}, 5) << " 2" << endl;
        cout << minOperations({5,6,7,8,9}, 4) << " -1" << endl;
    }

    int minOperations(vector<int>&& nums, int x) {
        int sum = 0-x, cur = 0;
        for (int i : nums) sum += i;
        if (sum < 0) return -1;
        int l = 0, r = 0, len = nums.size();
        if (sum == 0) return len;
        int res = -1;
        while (l < len && r < len) {
            if (cur < sum) {
                cur += nums[r++];
            } else if (cur > sum) {
                cur -= nums[l++];
            } else {
                res = max(res, r - l);
                cur -= nums[l++];
            }
        }
        if (cur == sum) res = max(res, r - l);
        return res == -1 ? res : len - res;
    }
};