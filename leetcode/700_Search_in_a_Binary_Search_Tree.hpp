#include "../base/icode.hpp"
class L700 : public icode
{
public:
	void run() {
        // [4,2,7,1,3] 2 -> [2,1,3]
    }

    TreeNode* searchBST(TreeNode* root, int val) {
        if (!root)
            return NULL;
        if (root->val == val) {
            return root;
        } else if (root->val < val) {
            return searchBST(root->right, val);
        } else {
            return searchBST(root->left, val);
        }
    }
};