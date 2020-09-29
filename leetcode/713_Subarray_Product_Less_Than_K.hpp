#include "../base/icode.hpp"
class L713 : public icode
{
public:
	void run() {
        vector<int> nums = {10, 5, 2, 6};
        cout << numSubarrayProductLessThanK(nums, 100) << " 8" << endl;
    }

    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;
        int prod = 1, ans = 0;
        size_t left = 0;
        for (size_t right = 0; right < nums.size(); right++) {
            prod *= nums[right];
            while (prod >= k) prod /= nums[left++];
            ans += right - left + 1;
        }
        return ans;
    }
};