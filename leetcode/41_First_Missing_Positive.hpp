#include "../base/icode.hpp"
class L41 : public icode
{
public:
	void run() {
        vector<int> nums = {1, 1};
        cout << firstMissingPositive(nums) << " 2" << endl;
        nums = {1,2,0};
        cout << firstMissingPositive(nums) << " 3" << endl;
        nums = {3,4,-1,1};
        cout << firstMissingPositive(nums) << " 2" << endl;
        nums = {7,8,9,11,12};
        cout << firstMissingPositive(nums) << " 1" << endl;
    }

    int firstMissingPositive(vector<int>& nums) {
        size_t i = 0;
        for (; i < nums.size(); ++i) {
            if (nums[i] > 0 && (size_t)nums[i] < nums.size() && (size_t)nums[i] != i + 1 && nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
                --i;
            }
        }
        for (i = 1; i <= nums.size(); ++i) {
            if (nums[i-1] != (int)i) {
                return i;
            }
        }
        return i;
    }
};