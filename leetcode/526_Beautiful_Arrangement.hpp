#include "../base/icode.hpp"
class L526 : public icode
{
public:
	void run() {
        cout << countArrangement(1) << " 1" << endl;
        cout << countArrangement(2) << " 2" << endl;
        cout << countArrangement(3) << " 3" << endl;
    }

    int countArrangement(int n) {
        vector<bool> vis(n, 0);
        int res = 0;
        calculate(vis, 1, res);
        return res;
    }
     void calculate(vector<bool> vis, int index, int& res) {
         int n = vis.size();
         if (index > n) {
             ++res;
         }
         for (int i = 1; i <= n; ++i) {
             if (!vis[i-1] && (i%index==0 || index%i==0)) {
                 vis[i-1] = 1;
                 calculate(vis, index + 1, res);
                 vis[i-1] = 0;
             }
         }
     }
};