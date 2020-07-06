#include "../base/icode.hpp"
/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

// @lc code=start
class L56 : public icode
{
public:
    struct cmp
    {
        bool operator()(const vector<int> &p, const vector<int> &q)
        {
            if (p[0] == q[0])
                return p[1] < q[1];
            return p[0] < q[0];
        }
    };

    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> res;
        if (intervals.empty())
            return res;
        sort(intervals.begin(), intervals.end(), cmp());
        res.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++)
        {
            if (res.back()[1] >= intervals[i][0])
            {
                intervals[i][0] = res.back()[0];
                intervals[i][1] = max(intervals[i][1], res.back()[1]);
                res.pop_back();
            }
            res.push_back(intervals[i]);
        }
        return res;
    }

    void run()
    {
        vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 12}, {15, 17}};
        icode::print_res(merge(intervals));
    }
};
// @lc code=end
