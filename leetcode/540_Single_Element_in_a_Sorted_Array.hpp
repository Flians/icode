#include "../base/icode.hpp"
class L540 : public icode {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int res = 0;
        for (auto num : nums)
            res ^= num;
        return res;
    }

    void run() {
        vector<int> nums = {1,1,2,3,3,4,4,8,8};
        cout << singleNonDuplicate(nums) << endl;
    }
};