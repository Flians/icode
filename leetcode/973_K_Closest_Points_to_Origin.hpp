#include "../base/icode.hpp"
class L973 : public icode
{
public:
	void run() {
        vector<vector<int>> points = {{3,3},{5,-1},{-2,4}};
        print_res(kClosest(points, 2));
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        auto lambda = [&](vector<int> &a, vector<int> &b){
            return a[1] < b[1];
        };

        priority_queue<vector<int>, vector<vector<int> >, decltype(lambda)> record{lambda};
        
        for (int i = 0; i < (int)points.size(); ++i) {
            int power = points[i][0]*points[i][0] + points[i][1]*points[i][1];
            if ((int)record.size() < K) {
                record.push({i, power});
            } else {
                if (record.top()[1] > power) {
                    record.pop();
                    record.push({i, power});
                }
            }
        }
        vector<vector<int> > res;
        res.reserve(K);
        while (!record.empty()) {
            res.push_back(points[record.top()[0]]);
            record.pop();
        }
        return res;
    }
};