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
class L113 : public icode
{
public:
	void run() {
        print_res(pathSum(create_tree({5,4,8,11,INT_MIN,13,4,7,2,INT_MIN,INT_MIN,5,1}), 22));
        // [[5,4,11,2],[5,8,4,5]];
    }

    void dfs(TreeNode* root, int val, vector<int> cur, vector<vector<int>> &res)  {
        if (!root) return;
        val -= root->val;
        cur.push_back(root->val);
        if (!root->right && !root->left) {
            if (val == 0) {
                res.push_back(cur);
            }
        }
        dfs(root->left, val, cur, res);
        dfs(root->right, val, cur, res);
    } 
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        dfs(root, targetSum, {}, res);
        return res;
    }
};