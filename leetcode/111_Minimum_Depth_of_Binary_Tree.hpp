#include "../base/icode.hpp"
class L111 : public icode
{
public:
	void run() {
        vector<int> nums = {2,-1,3,-1,4,-1,5,-1,6};
        cout << minDepth(create_tree<int, TreeNode>(nums)) << " 5" << endl;
        nums = {3,9,20,-1,-1,15,7};
        cout << minDepth(create_tree<int, TreeNode>(nums)) << " 2" << endl;
    }

    int minDepth(TreeNode* root) {
        if (!root)
            return 0;
        if (!root->left)
            return 1 + minDepth(root->right);
        if (!root->right)
            return 1 + minDepth(root->left);
        return 1 + min(minDepth(root->left), minDepth(root->right));
    }
};