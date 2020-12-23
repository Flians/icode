#include "../base/icode.hpp"
class L111 : public icode
{
public:
	void run() {
        cout << minDepth(create_tree<int, TreeNode>({2,INT_MIN,3,INT_MIN,4,INT_MIN,5,INT_MIN,6})) << " 5" << endl;
        cout << minDepth(create_tree<int, TreeNode>({3,9,20,INT_MIN,INT_MIN,15,7})) << " 2" << endl;
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