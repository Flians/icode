#include "../base/icode.hpp"
class L948 : public icode
{
public:
	void run() {
        vector<int> nums = {100};
        cout << bagOfTokensScore(nums, 50) << " 0" << endl;
        nums = {100, 200};
        cout << bagOfTokensScore(nums, 150) << " 1" << endl;
        nums = {100, 200, 300, 400};
        cout << bagOfTokensScore(nums, 200) << " 2" << endl;
    }

    int bagOfTokensScore(vector<int>& tokens, int P) {
        sort(tokens.begin(), tokens.end());
        int l = 0, r = tokens.size() - 1, res = 0, cur = 0;
        while (l <= r && (P >= tokens[l] || cur > 0)) {
            while (l <= r && P >= tokens[l]) {
                ++cur;
                P -= tokens[l++];
            }
            res = max(res, cur);
            while (l <= r && cur > 0 && P < tokens[r]) {
                --cur;
                P += tokens[r--];
            }
        }
        return res;
    }
};