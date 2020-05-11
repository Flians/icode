#include "../base/icode.h"
class L997 : public icode {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> degree(N+1, 0);
        for (auto item:trust) {
            --degree[item[0]];
            ++degree[item[1]];
        }
        for (int i=1; i <= N; ++i) {
            if (degree[i] == N-1)
                return i;
        }
        return -1;
    }

    void run() {
        vector<vector<int> > trust = {{1,3},{1,4},{2,3},{2,4},{4,3}};
        cout << findJudge(4, trust) << endl;
    }
};