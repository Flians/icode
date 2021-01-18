#include "../base/icode.hpp"
class L1646 : public icode
{
public:
	void run() {}

    int getMaximumGenerated(int n) {
        int res = 0;
        vector<int> nums(n+1, 0);
        if (n > 0) {
            nums[1] = 1;
        }
        for (size_t i = 1, nn = (n+1)/2; i <= nn; ++i) {
            if (i < nn) {
                nums[i*2] = nums[i];
                res = max(res, nums[i*2]);
            }
            nums[i*2 - 1] = nums[i] + nums[i - 1];
            res = max(res, nums[i*2 - 1]);
        }
        return res;
    }
};