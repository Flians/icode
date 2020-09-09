#include "../base/icode.hpp"
class L287 : public icode
{
public:
	void run() {
        vector<int> nums = {3,1,3,4,2};
        cout << findDuplicate(nums) << " 3" << endl;
        nums = {2, 2, 2, 2};
        cout << findDuplicate(nums) << " 2" << endl;
    }

    int findDuplicate(vector<int>& nums) {
        int fast = nums[0];
        int slow = nums[0];
        do {
            fast = nums[nums[fast]];
            slow = nums[slow];
        } while (fast != slow);
        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return fast;
    }
};