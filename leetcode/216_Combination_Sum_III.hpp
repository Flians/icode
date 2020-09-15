#include "../base/icode.hpp"
class L216 : public icode
{
public:
	void run() {
        print_res(combinationSum3(3, 9)); // [[1,2,6],[1,3,5],[2,3,4]]
    }

    void bt(int remain, int next_start, size_t k, vector<int> cur, vector<vector<int>> &res) {
        if (cur.size() == k) {
            if (remain == 0)
                res.emplace_back(cur);
            return;
        }
        for (int i = next_start; i <= 9; ++i) {
            cur.push_back(i);
            bt(remain - i, i+1, k, cur, res);
            cur.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        bt(n, 1, k, {}, res);
        return res;
    }
};