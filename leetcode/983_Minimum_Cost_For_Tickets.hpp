#include "../base/icode.hpp"
class L983 : public icode
{
private:
vector<int> durations = {1, 7, 30};
public:
	void run() {
        vector<int> days = {1,2,3,4,5,6,7,8,9,10,30,31};
        vector<int> costs = {2,7,15};
        cout << mincostTickets(days, costs) << " 17" << endl;
        days = {1,2,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,20,21,24,25,27,28,29,30,31,34,37,38,39,41,43,44,45,47,48,49,54,57,60,62,63,66,69,70,72,74,76,78,80,81,82,83,84,85,88,89,91,93,94,97,99};
        costs = {9,38,134};
        cout << mincostTickets(days, costs) << " 423" << endl;
    }

    int dfs(int index, vector<int> &days, vector<int> &costs, map<int, int> &dp) {
        if (index == (int)days.size()) {
            return 0;
        }
        if (dp.count(index))
            return dp[index];
        int minC = INT_MAX;
        size_t next = index;
        for (int i=0; i < 3; ++i) {
            while (next < days.size() && days[next] < days[index] + durations[i])
            {
                ++next;
            }
            minC = min(minC, dfs(next, days, costs, dp) + costs[i]);
        }
        dp[index] = minC;
        return minC;
    }
    
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        map<int, int> dp;
        return dfs(0, days, costs, dp);
    }
};