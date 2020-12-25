#include "../base/icode.hpp"
class L98 : public icode
{
public:
	void run() {
        cout << isValidBST(create_tree({1,1})) << " false" << endl;
        cout << isValidBST(create_tree({-2147483648})) << " true" << endl;
        cout << isValidBST(create_tree({5,4,6,INT_MIN,INT_MIN,3,7})) << " false" << endl;
    }

    bool inorder(TreeNode* root, double &pre) {
        if (!root) return true;
        if (!inorder(root->left, pre) || root->val <= pre) return false;
        pre = root->val;
        return inorder(root->right, pre);
    }

    bool isValidBST(TreeNode* root) {
        double pre = -DBL_MAX;
        return inorder(root, pre);
    }
};