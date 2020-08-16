#include "../base/icode.hpp"
class L435 : public icode
{
public:
	void run() {
        vector<vector<int>> intervals = {{1,100},{11,22},{1,11},{2,12}};
        cout << eraseOverlapIntervals(intervals) << " 2" << endl;
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty())
            return 0;
        sort(intervals.begin(), intervals.end(), [&](vector<int> &a, vector<int> &b){
            return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
        });
        int end = intervals[0][1];
        int num = 0;
        for (size_t i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] < end) {
                ++num;
                if(intervals[i][1] < end)
                    end = intervals[i][1];
            } else {
                end = intervals[i][1];
            }
        }
        return num;
    }

    int eraseOverlapIntervals_(vector<vector<int>>& intervals) {
        if (intervals.empty())
            return 0;
        sort(intervals.begin(), intervals.end(), [&](vector<int> &a, vector<int> &b){
            return a[1] == b[1] ? a[0] < b[0] : a[1] < b[1];
        });
        int end = intervals[0][1];
        int num = 0;
        for (size_t i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] < end) {
                ++num;
            } else {
                end = intervals[i][1];
            }
        }
        return num;
    }
};