#include "../base/icode.hpp"
class L35 : public icode
{
public:
	void run() {
        vector<int> nums = {1,3,5,6};
        cout << searchInsert(nums, 5) << " 2" << endl;
        cout << searchInsert(nums, 2) << " 1" << endl;
        cout << searchInsert(nums, 0) << " 0" << endl;
        cout << searchInsert(nums, 7) << " 4" << endl;
    }

    int searchInsert(vector<int>& nums, int target) {
        int l=0, r=nums.size();
        while (l < r) {
            int mid = l + (r-l)/2;
            // cout << mid << endl;
            if (nums[mid] < target)
            {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return r;
    }

    int searchInsert_(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        if (nums.back() < target)
            return nums.size();
        while (l < r) {
            int mid = l + (r - l)/2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};