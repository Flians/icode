#include "../base/icode.hpp"
class L404 : public icode
{
public:
	void run() {
        // [1,null,2] -> 0
        // [3,9,20,null,null,15,7] -> 24
    }

    
    int sumOfLeftLeaves(TreeNode* root, bool is_left = false) {
        if (!root)
            return 0;
        if (!root->left && !root->right && is_left)
            return root->val;
        return sumOfLeftLeaves(root->left, true) + sumOfLeftLeaves(root->right, false);
    }
};