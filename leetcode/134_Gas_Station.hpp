#include "../base/icode.hpp"
class L134 : public icode
{
public:
	void run() {
        vector<int> gas  = {1,2,3,4,5};
        vector<int> cost = {3,4,5,1,2};
        cout << canCompleteCircuit(gas, cost) << " 3" << endl;
        gas  = {2,3,4};
        cost = {3,4,3};
        cout << canCompleteCircuit(gas, cost) << " -1" << endl;
    }

    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum = 0;
        int tank = 0;
        int start = 0;
        for (size_t i = 0; i < gas.size(); ++i) {
            sum += gas[i] - cost[i];
            tank += gas[i] - cost[i];
            if (tank < 0) {
                tank = 0;
                start = i + 1;
            }
        }
        return sum < 0 ? -1 : start;
    }
};