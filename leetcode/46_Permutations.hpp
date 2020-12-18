#include "../base/icode.hpp"
class L46 : public icode
{
public:
    vector<vector<int>> permute(vector<int>&& nums)
    {
        vector<vector<int>> res;
        vector<int> item;
        item_per(nums, item, res);
        return res;
    }

    void item_per(vector<int> &nums, vector<int> item, vector<vector<int>> &res)
    {
        if (item.size() == nums.size())
        {
            res.push_back(item);
        }
        else
        {
            for (int i = 0; i < (int)nums.size(); i++)
            {
                if (find(item.begin(), item.end(), nums[i]) == item.end())
                {
                    item.push_back(nums[i]);
                    item_per(nums, item, res);
                    item.pop_back();
                }
            }
        }
    }

    void run()
    {
        icode::print_res(permute({1, 2, 3}));
    }
};