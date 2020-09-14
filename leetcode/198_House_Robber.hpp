#include "../base/icode.hpp"
class L198 : public icode
{
public:
	void run() {
        vector<int> nums = {2,7,9,3,1};
        cout << rob(nums) << " 12" << endl;
    }

    int rob(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        vector<pair<int,int>> dp(nums.size(), {0,0});
        dp[0].second = nums[0];
        for (size_t i = 1; i < nums.size(); ++i) {
            dp[i].first = max(dp[i-1].first, dp[i-1].second);
            dp[i].second = dp[i-1].first + nums[i];
        }
        return max(dp.back().first, dp.back().second);
    }
};