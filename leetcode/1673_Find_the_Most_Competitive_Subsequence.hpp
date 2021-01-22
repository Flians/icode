#include "../base/icode.hpp"
class L1673 : public icode
{
public:
    void run()
    {
        // [2,6]
        print_res(mostCompetitive({3, 5, 2, 6}, 2));
        // [2,3,3,4]
        print_res(mostCompetitive({2, 4, 3, 3, 5, 4, 9, 6}, 4));
    }

    vector<int> mostCompetitive(vector<int> &&nums, int k)
    {
        vector<int> stack;
        int nums_to_delete = nums.size() - k;
        for (int i = 0; i < nums.size(); i++)
        {
            while (!stack.empty() && nums[i] < stack.back() && nums_to_delete)
            {
                stack.pop_back();
                nums_to_delete--;
            }
            stack.push_back(nums[i]);
        }
        return vector<int>(stack.begin(), stack.begin() + k);
    }
};