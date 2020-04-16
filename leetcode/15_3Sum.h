#include "../base/icode.h"

vector<vector<int>> threeSum(vector<int> &nums, int i, int j)
{
    int k = 0;
    vector<vector<int>> triplets;
    if (j - i + 1 < 3)
        return triplets;
    while (i < j)
    {
        int temp_sum = nums[i] + nums[j];
        if (temp_sum + nums[i + 1] > 0 && temp_sum + nums[j - 1] < 0)
        {
            if (temp_sum < 0)
                i++;
            else
                j--;
        }
        else
        {
            for (k = i + 1; k < j; k++)
            {
                if (nums[k] + temp_sum == 0)
                {
                    vector<int> temp_v = {nums[i], nums[k], nums[j]};
                    triplets.push_back(temp_v);
                    break;
                }
            }
            vector<vector<int>> temp_i = threeSum(nums, i + 1, j);
            triplets.insert(triplets.end(), temp_i.begin(), temp_i.end());
            vector<vector<int>> temp_j = threeSum(nums, i, j - 1);
            triplets.insert(triplets.end(), temp_j.begin(), temp_j.end());
            i++, j--;
        }
    }
    return triplets;
}

vector<vector<int>> threeSum(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> triplets = threeSum(nums, 0, nums.size() - 1);
    sort(triplets.begin(), triplets.end());
    triplets.erase(unique(triplets.begin(), triplets.end()), triplets.end());
    return triplets;
}

class L15 : public icode
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> res;
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            int target = -nums[i];
            int front = i + 1;
            int back = nums.size() - 1;

            while (front < back)
            {

                int sum = nums[front] + nums[back];

                // Finding answer which start from number num[i]
                if (sum < target)
                    front++;

                else if (sum > target)
                    back--;

                else
                {
                    vector<int> triplet(3, 0);
                    triplet[0] = nums[i];
                    triplet[1] = nums[front];
                    triplet[2] = nums[back];
                    res.push_back(triplet);

                    // Processing duplicates of Number 2
                    // Rolling the front pointer to the next different number forwards
                    while (front < back && nums[front] == triplet[1])
                        front++;

                    // Processing duplicates of Number 3
                    // Rolling the back pointer to the next different number backwards
                    while (front < back && nums[back] == triplet[2])
                        back--;
                }
            }
            // Processing duplicates of Number 1
            while (i + 1 < nums.size() && nums[i + 1] == nums[i])
                i++;
        }
        return res;
    }

    void run()
    {
        vector<int> strs = {2, 2, -1, -3, 3, 1, -2, 1, -2, 3, 0, -5, 0, 4, -3, 3};
        vector<vector<int>> re = threeSum(strs);
        icode::print_res(re);
    }
};