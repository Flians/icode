#include "../base/icode.hpp"
class L152 : public icode
{
public:
	void run() {}

    int maxProduct(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int maxs = nums[0];
        int mins = nums[0];
        int max_res = nums[0];
        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] < 0)
                swap(maxs, mins);
            maxs = max(maxs*nums[i], nums[i]);
            mins = min(mins*nums[i], nums[i]);
            max_res = max(max_res, maxs);
        }
        return max_res;
    }
};