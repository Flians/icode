#include "../base/icode.hpp"
class L376 : public icode
{
public:
	void run() {}

    int wiggleMaxLength(vector<int>& nums) {
        std::size_t n = nums.size(), down = 1, up = 1;
        if (n < 2) return n;
        for (std::size_t i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1])
                up = down + 1;
            else if (nums[i] < nums[i - 1])
                down = up + 1;
        }
        return max(down, up);
    }
};