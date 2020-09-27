#include "../base/icode.hpp"
class L179 : public icode
{
public:
	void run() {
        vector<int> nums = {3,30,34,5,9};
        cout << largestNumber(nums) << " 9534330" << endl;
        nums = {0, 0};
        cout << largestNumber(nums) << " 0" << endl;
    }

    string largestNumber(vector<int>& nums) {
        vector<string> sn(nums.size());
        for (size_t i = 0; i < nums.size(); ++i) {
            sn[i] = to_string(nums[i]);
        }
        sort(sn.begin(), sn.end(), [&](string &a, string &b) {
            return a+b > b+a;
        });
        if (sn[0] == "0")
            return "0";
        string res = "";
        for (auto item:sn) {
            res += item;
        }
        return res;
    }
};