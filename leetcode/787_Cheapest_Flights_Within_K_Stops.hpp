#include "../base/icode.hpp"
class L787 : public icode
{
public:
	void run() {
        vector<vector<int>> flights = {{0,1,100},{1,2,100},{0,2,500}};
        cout << findCheapestPrice(3, flights, 0, 2, 1) << " 200" << endl;
        flights = {{0,1,2},{1,2,1},{2,0,10}};
        cout << findCheapestPrice(3, flights, 1, 2, 1) << " 6" << endl;
        flights = {{0,1,1},{0,2,5},{1,2,1},{2,3,1}};
        cout << findCheapestPrice(4, flights, 0, 3, 1) << " 6" << endl;
    }

    static bool cmp(tuple<int, int, int> &a, tuple<int, int, int> &b) {
        return get<1>(a) > get<1>(b);
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<pair<int, int>>> graph(n, vector<pair<int, int>>());
        for (auto& flight : flights) {
            graph[flight[0]].push_back({flight[1], flight[2]});
        }
        vector<tuple<int, int, int>> record;
        record.push_back({src, 0, -1});
        make_heap(record.begin(), record.end(), cmp);
        while (!record.empty()) {
            tuple<int, int, int> cur;
            pop_heap(record.begin(), record.end(), cmp);
            cur = record.back();
            record.pop_back();

            if (get<0>(cur) == dst)
                return get<1>(cur);

            if (get<2>(cur) < K) {
                for (auto &target : graph[get<0>(cur)]) {
                    record.push_back({target.first, get<1>(cur) + target.second, 1 + get<2>(cur)});
                    push_heap(record.begin(), record.end(), cmp);
                }
            }
        }
        return -1;
    }
};