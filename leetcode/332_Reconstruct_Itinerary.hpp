#include "../base/icode.hpp"
class L332 : public icode
{
public:
	void run() {
        vector<vector<string>> ticket = {{"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"}};
        print_res(findItinerary(ticket)); // ["JFK","ATL","JFK","SFO","ATL","SFO"]
        ticket = {{"EZE","TIA"},{"EZE","HBA"},{"AXA","TIA"},{"JFK","AXA"},{"ANU","JFK"},{"ADL","ANU"},{"TIA","AUA"},{"ANU","AUA"},{"ADL","EZE"},{"ADL","EZE"},{"EZE","ADL"},{"AXA","EZE"},{"AUA","AXA"},{"JFK","AXA"},{"AXA","AUA"},{"AUA","ADL"},{"ANU","EZE"},{"TIA","ADL"},{"EZE","ANU"},{"AUA","ANU"}};
        print_res(findItinerary(ticket)); // ["JFK","AXA","AUA","ADL","ANU","AUA","ANU","EZE","ADL","EZE","ANU","JFK","AXA","EZE","TIA","AUA","AXA","TIA","ADL","EZE","HBA"]
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, priority_queue<string, vector<string>, greater<string>>> iti;
        for (auto &item : tickets) {
            iti[item[0]].push(item[1]);
        }
        vector<string> res;
        stack<string> lef;
        lef.push("JFK");
        while (!lef.empty()) {
            string cur = lef.top();
            if (iti[cur].empty()) {
                lef.pop();
                res.push_back(cur);
            } else {
                lef.push(iti[cur].top());
                iti[cur].pop();
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};