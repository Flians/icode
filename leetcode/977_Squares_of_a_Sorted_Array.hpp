#include "../base/icode.hpp"
class L977 : public icode
{
public:
	void run() {
        vector<int> nums = {-7,-3,2,3,11};
        // [4,9,9,49,121]
        print_res(sortedSquares(nums));
    }

    vector<int> sortedSquares(vector<int>& nums) {
        int i = nums.size() - 1;
        vector<int> res(i + 1, 0);
        int l = 0, r = i;
        while (l <= r) {
            if (abs(nums[r]) >= abs(nums[l])) {
                res[i--] = nums[r] * nums[r];
                --r;
            } else {
                res[i--] = nums[l] * nums[l];
                ++l;
            }
        }
        return res;
    }
};