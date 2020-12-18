#include "../base/icode.hpp"
class L312 : public icode
{
public:
	void run() {
        cout << maxCoins({35,16,83,87,84,59,48,41,20,54}) << " 1849648" << endl;
    }

    int fun_dfs(vector<int> nums) {
        int cur_max = 0, len = nums.size();
        for (int i = 0; i < len; ++i) {
            int tmp = nums[i];
            if (i > 0) {
                tmp *= nums[i-1];
            }
            if (i < len - 1) {
                tmp *= nums[i+1];
            }
            int cur = nums[i];
            nums.erase(nums.begin() + i);
            cur_max = max(cur_max, fun_dfs(nums) + tmp);
            nums.insert(nums.begin() + i, cur);
        }
        return cur_max;
    }
    
    int fun_dp(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) {
            return 0;
        }
        len += 2;
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> dp(len, vector<int>(len, 0));
        for (int l = 2; l < len; ++l) {
            for (int s = 0; s < len - l; ++s) {
                int end = s + l;
                for (int m = s + 1; m < end; ++m) {
                    dp[s][end] = max(dp[s][end], nums[s]*nums[m]*nums[end] + dp[s][m] + dp[m][end]);
                }
            }
        }
        return dp[0][len-1];
    }
    
    int maxCoins(vector<int>&& nums) {
        return fun_dp(nums);
    }
};