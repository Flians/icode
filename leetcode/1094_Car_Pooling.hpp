#include "../base/icode.hpp"
class L1094 : public icode
{
public:
	void run() {
        vector<vector<int>> trips = {{2,1,5}, {3,3,7}};
        cout << carPooling(trips, 4) << " false" << endl;
        cout << carPooling(trips, 5) << " true" << endl;
        trips = {{2,1,5}, {3,5,7}};
        cout << carPooling(trips, 3) << " true" << endl;
        trips = {{3,2,7}, {3,7,9}, {8,3,9}};
        cout << carPooling(trips, 11) << " true" << endl;
    }

    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> people(1001, 0);
        for (auto trip : trips) {
            people[trip[1]] += trip[0];
            people[trip[2]] -= trip[0];
        }
        int cur = 0;
        for (auto p : people) {
            cur += p;
            if (cur > capacity) {
                return false;
            }
        }
        return true;
    }
};