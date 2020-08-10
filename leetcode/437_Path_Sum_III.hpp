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
class L437 : public icode
{
public:
	void run() {
        // root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8 -> 3
    }

    int DFS(TreeNode *root,int sum){
        return root?(root->val==sum) + DFS(root->left,sum-root->val) + DFS(root->right,sum-root->val):0;
    }
    int pathSum(TreeNode* root, int sum) {
        return root? DFS(root,sum) + pathSum(root->left,sum) + pathSum(root->right,sum):0;
    }
};