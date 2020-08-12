#include "../base/icode.hpp"
class L368 : public icode
{
public:
	void run() {
        vector<int> nums = {5,9,18,54,108,540,90,180,360,720};
        print_res(largestDivisibleSubset(nums));
    }

    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> subset;
        if (nums.empty()) {
            return subset;
        }
        sort(nums.begin(), nums.end());
        vector<int> dp(nums.size(), 1);
        vector<int> pre(nums.size(), -1);
        int maxI = 0;
        for (size_t i = 0; i < nums.size(); ++i) {
            for (size_t j = 0; j < i; ++j) {
                if (nums[i] < nums[j])
                    break;
                if (nums[i] % nums[j] == 0) {
                    if (dp[i] < dp[j]+1) {
                        dp[i] = dp[j]+1;
                        pre[i] = j;
                    }
                }
            }
            if (dp[maxI] < dp[i]) {
                maxI = i;
            }
        }
        int len = dp[maxI];
        for (int i = 0; i < len; ++i) {
            subset.emplace_back(nums[maxI]);
            maxI = pre[maxI];
        }
        return subset;
    }
};