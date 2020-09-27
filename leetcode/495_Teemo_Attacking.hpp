#include "../base/icode.hpp"
class L495 : public icode
{
public:
	void run() {
        vector<int> timeSeries = {1,4};
        cout << findPoisonedDuration(timeSeries, 2) << " 4" << endl;
        timeSeries = {1,2};
        cout << findPoisonedDuration(timeSeries, 2) << " 3" << endl;
    }

    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int total = 0, beg = 0, end = 0;
        if (timeSeries.empty()) {
            return total;
        }
        beg = timeSeries[0];
        end = duration + timeSeries[0];
        for (size_t i = 1; i < timeSeries.size(); ++i) {
            if (timeSeries[i] >= end) {
                total += end - beg;
                beg = timeSeries[i];
            }
            end = timeSeries[i] + duration;
        }
        total += end - beg;
        return total;
    }
};