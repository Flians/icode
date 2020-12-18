#include "../base/icode.hpp"
class L75 : public icode
{
public:
	void run() {
        vector<int> nums = {2,0,2,1,1,0};
        sortColors(nums);
        print_res(move(nums));
    }

    void sortColors(vector<int>& nums) {
        int l = 0, m = 0, r = nums.size() - 1;
        while (m <= r) {
            switch(nums[m]) {
                case 0:
                    swap(nums[l++], nums[m++]);
                    break;
                case 1:
                    ++m;
                    break;
                default:
                    swap(nums[m], nums[r--]);
            }
        }
    }

    void sortColors_(vector<int>& nums) {
        int one = 0, two = 0, three = 0;
        for (size_t i = 0; i < nums.size(); ++i) {
            switch(nums[i]) {
                case 0:
                    ++one;
                    break;
                case 1:
                    ++two;
                    break;
                default:
                    ++three;
            }
        }
        size_t i = 0;
        while (i < nums.size()) {
            while (one--) {
                nums[i++] = 0;
            }
            while (two--) {
                nums[i++] = 1;
            }
            while (three--) {
                nums[i++] = 2;
            }
        }
    }
};