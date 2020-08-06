#include "../base/icode.hpp"
class L886 : public icode
{
public:
	void run() {
        vector<vector<int> > dislikes = {{1,2},{2,3},{3,4},{4,5},{1,5}};
        cout << possibleBipartition(5, dislikes) << " false" << endl;
    }

    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<vector<int> > group(N+1);
        for(auto &item : dislikes) {
            group[item[0]].emplace_back(item[1]);
        }
        int i = 0;
        vector<int> colors(N + 1, -1);
        while (true) {
            for (i = 1; i <= N; ++i) {
                if (colors[i] == -1 && !group[i].empty())
                    break;
            }
            if (i == N+1)
                break;
            for (int child : group[i]) {
                if (colors[child] != -1) {
                    colors[i] = !colors[child];
                    break;
                }
            }
            queue<int> record;
            record.push(i);
            while (!record.empty()) {
                int root = record.front();
                record.pop();
                int color = colors[root];
                for (int child : group[root]) {
                    if (colors[child] == -1) {
                        colors[child] = !color;
                        record.push(child);
                    } else if (colors[child] == color) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};