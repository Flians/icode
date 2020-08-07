#include "../base/icode.hpp"
class L406 : public icode
{
public:    
	void run() {}

    vector<vector<int>> reconstructQueue_(vector<vector<int>>& people) {
        list<vector<int>> res_list;
        for (auto &item : people) {
            sort(people.begin(), people.end(), [&](vector<int> &a, vector<int> &b) {
                return a[0] == b[0] ? a[1] < b[1] : a[0] > b[0];
            });
            int i = item[1];
            list<vector<int> >::iterator it = res_list.begin();
            while (i--) {
                ++it;
            }
            res_list.insert(it, item);
        }
        vector<vector<int>> res(res_list.begin(), res_list.end());
        return res;
    }

    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n = people.size();
        vector<vector<int>> res(n, vector<int>(2, INT_MAX));
        sort(people.begin(), people.end());
        for(auto p : people) {
            int cnt = 0, i;
            for(i = 0; i < n && cnt < p[1]; ++i) {
                if(res[i][0] >= p[0])
                    ++cnt;
            }
            while(res[i][0] != INT_MAX)
                ++i;
            res[i] = p;
        }
        return res;
    }
};