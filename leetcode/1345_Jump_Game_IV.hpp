#include "../base/icode.hpp"
class L1345 : public icode
{
public:
	void run() {
        cout << minJumps({11,22,7,7,7,7,7,7,7,22,13}) << " 3" << endl;
        cout << minJumps({100,-23,-23,404,100,23,23,23,3,404}) << " 3" << endl;
        cout << minJumps({6,1,9}) << " 2" << endl;
        cout << minJumps({7}) << " 0" << endl;
    }

    int minJumps(vector<int>&& arr) {
        size_t len = arr.size();
        map<int, vector<int>> record;
        for (size_t i = 0; i < len; ++i) {
            if (!record.count(arr[i])) {
                vector<int> item;
                record[arr[i]] = item;
            }
            record[arr[i]].push_back(i);
        }
        int res = -1;
        queue<int> cur;
        cur.push(0);
        vector<bool> visited(len, 0);
        while (!cur.empty()) {
            ++res;
            size_t num = cur.size();
            while (num--) {
                size_t i = cur.front();
                cur.pop();
                if (i == len - 1) return res;
                if (i > 0 && !visited[i-1]) {
                    visited[i-1] = 1;
                    cur.push(i-1);
                }
                if (i < len - 1 && !visited[i+1]) {
                    visited[i+1] = 1;
                    cur.push(i+1);
                }
                for (auto t : record[arr[i]]) {
                    if (!visited[t]) {
                        visited[t] = 1;
                        cur.push(t);
                    }
                }
                record[arr[i]].clear();
            }
        }
        return res;
    }
};