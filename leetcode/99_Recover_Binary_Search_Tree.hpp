#include "../base/icode.hpp"
class L99 : public icode
{
private:
    TreeNode *left = NULL, *right = NULL, *last = NULL;

public:
    void run()
    {
        TreeNode *root = create_tree({1, 3, -1, -1, 2});
        recoverTree(root);
        print_res(root); // [3,1,null,null,2]
    }

    void inorder(TreeNode *root)
    {
        if (!root)
            return;
        inorder(root->left);
        if (last && last->val > root->val)
        {
            if (!left)
                left = last;
            right = root;
        }
        last = root;
        inorder(root->right);
    }
    void recoverTree(TreeNode *root)
    {
        inorder(root);
        if (left && right)
            std::swap(left->val, right->val);
    }
};