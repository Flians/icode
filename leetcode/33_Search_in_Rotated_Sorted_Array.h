#include "../base/icode.h"

class L33 : public icode {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty())
            return -1;
        int left=0,right=nums.size()-1;
        while (left <= right) {
            int mid = (left + right) >> 1;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[left] > nums[right]) { // rotated
                if (target > nums[right] && target < nums[left])
                    return -1;
                if (target <= nums[right]) {
                    if (nums[mid] < target) {
                        left = mid + 1;
                    } else if (nums[mid] > target) {
                        if (nums[mid] <= nums[right]) {
                            right = mid - 1;
                        } else {
                            left = mid + 1; 
                        }
                    }
                } else {
                    if (nums[mid] < target) {
                        if (nums[mid] <= nums[right]) {
                            right = mid - 1;
                        } else {
                            left = mid + 1; 
                        }
                    } else if (nums[mid] > target) {
                        right = mid -1;
                    }
                }
            } else { // ascending
                if (nums[mid] < target) {
                    left = mid + 1;
                } else if (nums[mid] > target) {
                    right = mid -1;
                }
            }
        }
        return -1;
    }

    void run() {
        int a[7] = {4,5,6,7,0,1,2};
        vector<int> nums(a, a+7);
        int target = 0;
        cout << search(nums, target) << endl;
    }
};