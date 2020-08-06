#include "../base/icode.hpp"
class L226 : public icode
{
public:
	void run() {
        // [4,2,7,1,3,6,9] -> [4,7,2,9,6,3,1]
    }

    TreeNode* invertTree(TreeNode* root) {
        if (root) {
            swap(root->left, root->right);
            invertTree(root->left);
            invertTree(root->right);
        }
        return root;
    }
};