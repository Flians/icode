#include "../base/icode.hpp"
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class L337 : public icode
{
private:
    map<pair<TreeNode*, bool>, int> dp;
public:
	void run() {
        vector<int> nums = {3,4,5,1,3,-1,1};
        cout << rob(create_tree<int, TreeNode>(nums)) << " 9" << endl;
    }

    int fun(TreeNode* root, bool flag) {
        if (dp.count({root, flag})) {
            return dp[{root, flag}];
        }
        int res = 0;
        if (!root) {
            return res;
        }
        if (!flag) {
            res += root->val;
            res += fun(root->left, true);
            res += fun(root->right, true);
        }
        int tmp = fun(root->left, false) + fun(root->right, false);
        dp[{root, true}] = tmp;
        dp[{root, false}] = max(tmp, res);
        return dp[{root, false}];
    }
    int rob(TreeNode* root) {
        dp.clear();
		return max(fun(root, 0), fun(root, 1));
	}
};