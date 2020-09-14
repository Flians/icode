#include "../base/icode.hpp"
class L213 : public icode
{
public:
	void run() {}

    int rob(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        if (nums.size() == 1)
            return nums[0];
        vector<pair<int,int>> dp(nums.size(), {0,0});
        dp[1].second = nums[1];
        for (size_t i = 2; i < nums.size(); ++i) {
            dp[i].first = max(dp[i-1].first, dp[i-1].second);
            dp[i].second = dp[i-1].first + nums[i];
        }
        int first = max(dp.back().first, dp.back().second);
        dp.resize(nums.size(), {0,0});
        dp[0].second = nums[0];
        for (size_t i = 1; i < nums.size()-1; ++i) {
            dp[i].first = max(dp[i-1].first, dp[i-1].second);
            dp[i].second = dp[i-1].first + nums[i];
        }
        return max(first, max(dp[nums.size()-2].first, dp[nums.size()-2].second));
    }
};