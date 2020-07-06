#include "../base/icode.hpp"
/*
 * @lc app=leetcode id=57 lang=cpp
 *
 * [57] Insert Interval
 */

// @lc code=start
class L57 : public icode
{
public:
	void run() {
        vector<vector<int>> intervals = {{1,5},{6,7}};
        vector<int> newInterval = {0,0};
        icode::print_res(insert(intervals, newInterval));
    }

    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        vector<vector<int>> res;
        if (intervals.empty() || newInterval.empty())
        {
            if (!newInterval.empty())
                res.push_back(newInterval);
            return res;
        }
        int flag = 0;
        for (int i = 0; i < intervals.size(); i++)
        {
            if (intervals[i][1] < newInterval[0] && flag == 0)
            {
                res.push_back(intervals[i]);
                if (i == intervals.size() - 1)
                {
                    res.push_back(newInterval);
                }
            }
            else
            {
                if (flag == 0) flag = 1;
                if (intervals[i][0] <= newInterval[1])
                {
                    newInterval[0] = min(intervals[i][0], newInterval[0]);
                    newInterval[1] = max(intervals[i][1], newInterval[1]);
                    if (i == intervals.size() - 1)
                    {
                        res.push_back(newInterval);
                    }
                }
                else
                {
                    if (flag == 1)
                    {
                        flag = 2;
                        res.push_back(newInterval);
                    }
                    res.push_back(intervals[i]);
                }
            }
        }
        return res;
    }
};
// @lc code=end
