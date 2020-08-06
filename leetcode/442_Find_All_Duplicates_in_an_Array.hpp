#include "../base/icode.hpp"
class L442 : public icode
{
public:
	void run() {
        vector<int> nums = {4,3,2,7,8,2,3,1};
        print_res(findDuplicates(nums));
        nums = {1,1};
        print_res(findDuplicates(nums));
    }

    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        for (int i = 1; i <= (int)nums.size(); ++i) {
            if (nums[i-1] != i) {
                if (nums[nums[i-1] - 1] == nums[i-1]) {
                    res.emplace_back(nums[i-1]);
                } else {
                    swap(nums[i-1], nums[nums[i-1] - 1]);
                    --i;
                }
            }
        }
        set<int> uniq(res.begin(), res.end());
        res.assign(uniq.begin(), uniq.end());
        return res;
    }
};