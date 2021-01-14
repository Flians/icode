#include "../base/icode.hpp"
class L881 : public icode
{
public:
	void run() {
        cout << numRescueBoats({5,1,7,4,2,4}, 7) << " 4" << endl;
    }

    int numRescueBoats(vector<int>&& people, int limit) {
        sort(people.begin(), people.end());
        int res = 0;
        int l = 0, r = people.size() - 1;
        while (l <= r) {
            if (people[l] + people[r] <= limit) {
                ++l;
            }
            ++res;
            --r;
        }
        return res;
    }
};