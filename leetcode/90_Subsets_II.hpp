#include "../base/icode.hpp"

class L90 : public icode {
public:
    void run() {
	// [[],[1],[1,2],[1,2,2],[2],[2,2]]
        print_res(subsetsWithDup({1,2,2}));
    }
    void dfs(int index, int nums[], vector<int> cur, vector<vector<int>> &res) {
        if (index == 21) {
            res.push_back(cur);
        } else {
            for (int i = 0; i <= nums[index]; ++i) {
                if (i > 0) cur.push_back(index - 10);
                dfs(index + 1, nums, cur, res);
            }
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>&& nums) {
        int _nums[21] = {0};
        for (int i : nums) {
            ++_nums[i+10];
        }
        vector<vector<int>> res;
        dfs(0, _nums, {}, res);
        return res;
    }
};
