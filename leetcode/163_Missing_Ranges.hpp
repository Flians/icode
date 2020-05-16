#include "../base/icode.hpp"

class L163 : public icode
{
public:
    vector<string> findMissingRanges(vector<int> &nums, int lower, int upper)
    {
        vector<string> res;
        for (int num : nums)
        {
            if (num > lower)
                res.push_back(to_string(lower) + (num - 1 > lower ? ("->" + to_string(num - 1)) : ""));
            if (num == upper)
                return res;
            lower = num + 1;
        }
        if (lower <= upper)
            res.push_back(to_string(lower) + (upper > lower ? ("->" + to_string(upper)) : ""));
        return res;
    }

    void run() {
        vector<int> nums = {0, 1, 3, 50, 75};
        print_res(findMissingRanges(nums, 0, 99));
    }
};