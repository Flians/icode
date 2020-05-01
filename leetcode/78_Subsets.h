#include "../base/icode.h"
class L78 : public icode {
public:
    vector<vector<int>> subsets_re(vector<int>& nums) {
        vector<vector<int> > res;
        vector<int> item;
        res.push_back(item);
        
        for (auto num:nums) {
            int len = res.size();
            for (int i=0; i<len; ++i) {
                item = res[i];
                item.push_back(num);
                res.push_back(item);
            }
        }
        return res;
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        return subsets_re(nums);
    }

    void run() {
        vector<int> nums={1,2,3};
        print_res(subsets(nums));
    }
};