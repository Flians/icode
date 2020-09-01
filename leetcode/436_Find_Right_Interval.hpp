#include "../base/icode.hpp"
class L436 : public icode
{
public:
	void run() {}

    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        map<int, int> record;
        vector<int> res(intervals.size(), -1);
        for(size_t i = 0; i < intervals.size(); i++)
            record[intervals[i][0]] = i;
        for(size_t i = 0; i < intervals.size(); i++) {
            auto tmp = record.lower_bound(intervals[i][1]);
            res[i]  = tmp!=end(record) ? tmp->second : -1;
        }
        return res;
    }
};