#include "../base/icode.hpp"
class L556 : public icode
{
public:
	void run() {
        cout << nextGreaterElement(21) << " -1" << endl;
        cout << nextGreaterElement(623541) << " 624135" << endl;
        cout << nextGreaterElement(1999999999) << " -1" << endl;
    }

    int nextGreaterElement(int n) {
        vector<int> nums;
        while (n) {
            nums.push_back(n%10);
            n /= 10;
        }
        long i = 0, j = nums.size();
        for (i = 1; i < j; ++i) {
            if (nums[i] < nums[i-1]) {
                break;
            }
        }
        if (i == j) return -1;
        for (j = 0; j < i; ++j) {
            if (nums[j] > nums[i]) {
                break;
            }
        }
        swap(nums[i],nums[j]);
        reverse(nums.begin(), nums.begin() + i);
        i = 1;
        long res = 0;
        for (auto x:nums) {
            res += x*i;
            if (res > INT_MAX) return -1;
            i *= 10;
        }
        return res;
    }
};