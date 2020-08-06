#include "../base/icode.hpp"
class L1029 : public icode
{
public:
	void run() {
        vector<vector<int>> costs = {{10,20},{30,200},{400,50},{30,20}};
        cout << twoCitySchedCost(costs) << " 110" << endl;
        costs = {{259,770},{448,54},{926,667},{184,139},{840,118},{577,469}};
        cout << twoCitySchedCost(costs) << " 1859" << endl;
    }

    int twoCitySchedCost(vector<vector<int>>& costs) {
        int sum = 0;
        sort(costs.begin(), costs.end(), [&](vector<int> &a, vector<int> &b){
            return a[0] - a[1] < b[0] - b[1];
        });
        for (size_t i = 0; i < costs.size(); ++i) {
            sum += i<costs.size()/2 ? costs[i][0] : costs[i][1];
        }
        return sum;
    }
};