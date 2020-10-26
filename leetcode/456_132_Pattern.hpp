#include "../base/icode.hpp"
class L456 : public icode
{
public:
	void run() {
        vector<int> nums = {1,2,3,4};
        cout << find132pattern(nums) << " false" << endl;
        nums = {3,1,4,2};
        cout << find132pattern(nums) << " true" << endl;
        nums = {-1,3,2,0};
        cout << find132pattern(nums) << " true" << endl;
    }

    bool find132pattern(vector<int>& nums) {
        int i = INT_MAX;
        for (size_t j = 0; j < nums.size(); ++ j) {
            i = min(i, nums[j]);
            for (size_t k = j + 1; k < nums.size(); ++k) {
                if (i < nums[k] && nums[k] < nums[j])
                    return true;
            }
        }
        return false;
    }
};