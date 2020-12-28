#include "../base/icode.hpp"
class L1696 : public icode
{
public:
	void run() {
        cout << maxResult({1,-1,-2,4,-7,3}, 2) << " 7" << endl;
        cout << maxResult({1,-5,-20,4,-1,3,-6,-3}, 2) << " 0" << endl;
    }

    int maxResult(vector<int>&& nums, int k) {
        size_t len = nums.size();
        vector<int> dp(len, 0);
        dp[0] = nums[0];
        for (size_t i = 1; i < len; ++i) {
            int tmp = dp[i-1];
            for (int j = i - 2, range = i <= k?0:i-k;  j >= range; --j) {
                tmp = max(tmp, dp[j]);
            }
            dp[i] = nums[i] + tmp;
        }
        return dp[len-1];
    }

    int maxResult_monodeq(vector<int>&& nums, int k) {
        deque<int> d{0};
        for (int i = 1; i < nums.size(); ++i) {
            if (d.front() + k < i)
                d.pop_front();        
            nums[i] += nums[d.front()];
            while (!d.empty() && nums[d.back()] <= nums[i])
                d.pop_back();
            d.push_back(i);
        }
        return nums.back();
    }
};