#include "../base/icode.hpp"
class L110 : public icode
{
public:
	void run() {
        cout << isBalanced(create_tree({3,9,20,INT_MIN,INT_MIN,15,7})) << " true" << endl;
        cout << isBalanced(create_tree({1,2,2,3,3,INT_MIN,INT_MIN,4,4})) << " false" << endl;
        cout << isBalanced(create_tree({})) << " true" << endl;
    }

    int dfs(TreeNode* root) {
        if (!root) return 0;
        int l = dfs(root->left);
        if (l == -1) return -1;
        int r = dfs(root->right);
        if (r == -1) return -1;
        return abs(l-r) > 1 ? -1 : max(l, r) + 1;
    }
    bool isBalanced(TreeNode* root) {
        return dfs(root) != -1;
    }
};