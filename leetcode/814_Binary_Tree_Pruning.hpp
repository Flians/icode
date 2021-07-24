#include "../base/icode.hpp"
class L814 : public icode
{
public:
    void run()
    {
        print_res(pruneTree(create_tree({0, INT_MIN, 0, 0, 0})));
    }

    void postorder(TreeNode *root)
    {
        if (!root)
            return;
        postorder(root->left);
        if (root->left && root->left->val == -1)
        {
            delete root->left;
            root->left = NULL;
        }
        postorder(root->right);
        if (root->right && root->right->val == -1)
        {
            delete root->right;
            root->right = NULL;
        }
        if (!root->val && !root->left && !root->right)
        {
            root->val = -1;
        }
    }
    TreeNode *pruneTree(TreeNode *root)
    {
        postorder(root);
        if (root && root->val == -1)
        {
            delete root;
            root = NULL;
        }
        return root;
    }
};