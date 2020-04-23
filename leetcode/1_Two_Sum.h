#include "../base/icode.h"

class L1 : public icode
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int i = 0, j = 0;
        vector<int> indices;
        for (; i < (int)nums.size(); i++)
        {
            if (nums[i] > target)
                continue;
            for (j = i + 1; j < (int)nums.size(); j++)
            {
                if (nums[j] > target)
                    continue;
                if (nums[i] + nums[j] == target)
                {
                    indices.push_back(i);
                    indices.push_back(j);
                }
            }
        }
        return indices;
    }

    void run()
    {
        int a[4] = {2,7,11,15};
        vector<int> ilist(a, a+4);
        icode::print_res(twoSum(ilist, 9)); 
    }
};