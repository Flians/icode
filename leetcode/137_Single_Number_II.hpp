#include "../base/icode.hpp"
class L137 : public icode
{
public:
	void run() {
        vector<int> nums = {0,1,0,1,0,1,99};
        cout << singleNumber(nums) << " 99" << endl;
        nums = {43,16,45,89,45,-2147483648,45,2147483646,-2147483647,-2147483648,43,2147483647,-2147483646,-2147483648,89,-2147483646,89,-2147483646,-2147483647,2147483646,-2147483647,16,16,2147483646,43};
        cout << singleNumber(nums) << " 2147483647" << endl;

    }

    int singleNumber(vector<int>& nums) {
        long long all_sum = 0;
        long long distinct_sum = 0;
        unordered_map<int, bool> distinct;
        for (auto &it : nums) {
            all_sum += it;
            if (!distinct.count(it)) {
                distinct[it] = 1;
                distinct_sum += it;
            }
        }
        return (distinct_sum*3 - all_sum) / 2;
    }
};