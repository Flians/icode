#include "../base/icode.hpp"
class L1679 : public icode
{
public:
	void run() {
        cout << maxOperations({1,2,3,4}, 5) << " 2" << endl;
        cout << maxOperations({3,1,3,4,3}, 6) << " 1" << endl;
    }

    int maxOperations(vector<int>&& nums, int k) {
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.size() - 1, res = 0;
        while (l < r) {
            int tmp  = nums[l] + nums[r];
            if (tmp == k) {
                ++res, ++l, --r;
            } else if (tmp < k) {
                ++l;
            } else {
                --r;
            }
        }
        return res;
    }
};