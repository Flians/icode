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
class L987 : public icode
{
public:
	void run() {}

    void verticalTraversal(TreeNode* root, int &index, vector<vector<int> > &res) {
        if (!root)
            return;
        if (index == 0) {
            vector<int> item;
            item.emplace_back(root->val);
            res.insert(res.begin(), item);
            verticalTraversal(root->left, index, res);
            verticalTraversal(root->right, ++index, res);
        } if (index >= res.size()) {
            vector<int> item;
            item.emplace_back(root->val);
            res.emplace_back(item);
            verticalTraversal(root->left, --index, res);
            verticalTraversal(root->right, ++index, res);
        } else {
            res[index].emplace_back(root->val);
            verticalTraversal(root->left, --index, res);
            verticalTraversal(root->right, ++index, res);
        }
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        int index = 0;
        vector<vector<int> > res;
        verticalTraversal(root, index, res);
        return res;
    }
};