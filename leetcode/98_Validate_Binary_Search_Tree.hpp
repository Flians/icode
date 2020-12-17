#include "../base/icode.hpp"
class L98 : public icode
{
public:
	void run() {
        vector<int> nums = {1,1};
        cout << isValidBST(create_tree<int, TreeNode>(nums)) << " false" << endl;
        nums = {-2147483648};
        cout << isValidBST(create_tree<int, TreeNode>(nums)) << " true" << endl;
        nums ={5,4,6,-1,-1,3,7};
        cout << isValidBST(create_tree<int, TreeNode>(nums)) << " false" << endl;
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