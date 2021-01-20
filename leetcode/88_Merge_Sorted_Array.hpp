#include "../base/icode.hpp"
class L88 : public icode
{
public:
	void run() {
        vector<int> nums1 = {1}, nums2 = {};
        // [1]
        merge(nums1, 1, nums2, 0);
        print_res(move(nums1)); // [1]
        nums1 = {0}, nums2 = {1};
        // [1]
        merge(nums1, 0, nums2, 1);
        print_res(move(nums1));
        nums1 = {-12,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
        nums2 = {-49,-45,-42,-41,-40,-39,-39,-39,-38,-36,-34,-34,-33,-33,-32,-31,-29,-28,-26,-26,-24,-21,-20,-20,-18,-16,-16,-14,-11,-7,-6,-5,-4,-4,-3,-3,-2,-2,-1,0,0,0,2,2,6,7,7,8,10,10,13,13,15,15,16,17,17,19,19,20,20,20,21,21,22,22,24,24,25,26,27,29,30,30,30,35,36,36,36,37,39,40,41,42,45,46,46,46,47,48};
        // [-49,-45,-42,-41,-40,-39,-39,-39,-38,-36,-34,-34,-33,-33,-32,-31,-29,-28,-26,-26,-24,-21,-20,-20,-18,-16,-16,-14,-12,-11,-7,-6,-5,-4,-4,-3,-3,-2,-2,-1,0,0,0,2,2,6,7,7,8,10,10,13,13,15,15,16,17,17,19,19,20,20,20,21,21,22,22,24,24,25,26,27,29,30,30,30,35,36,36,36,37,39,40,41,42,45,46,46,46,47,48]
        merge(nums1, 1, nums2, 90);
        print_res(move(nums1));
    }

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0, j = 0;
        while (i < m + j && j < n)
        {
            if (i > 0 && nums1[i] < nums1[i-1]) {
                break;
            }
            if (nums1[i] < nums2[j])
            {
                ++i;
            } else {
                while (j < n && nums1[i] >= nums2[j]) {
                    nums1.insert(nums1.begin() + (i++), nums2[j++]);
                }
            }
        }
        if (j < n) {
            nums1.insert(nums1.begin() + i, nums2.begin() + j, nums2.begin() + n);
        }
        nums1.resize(m + n);
        vector<int>(nums1).swap(nums1);
    }
};