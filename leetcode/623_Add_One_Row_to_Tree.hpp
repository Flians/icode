#include "../base/icode.hpp"

class L623 : public icode
{
public:
    void run()
    {
        print_res(addOneRow(create_tree({1, 5, 8, 9, 7, 7, 8, 1, 4, 8, 1, 9, 0, 8, 7, 1, 7, 4, 2, 9, 8, 2, 4, -1, -1, 9, -1, -1, -1, 6, 0, 9, 4, 1, 0, 1, 8, 9, 0, 1, 8, 9, 1, 0, 9, 6, 2, 5, -1, 2, 3, 0, 2, 4, 8, 8, 8, 5, 0, 0, 9, 4, 9, 1, -1, 0, 7, 2, 2, 3, -1, 6, 1, 0, 8, 9, 9, 9, 4, 8, 4, 3, 4, 4, 0, -1, -1, 8, 3, 8, -1, -1, 0, -1, 0, 4, 9, 1, 2, -1, 4, 4, 0, 4, 3, 5, 5, 7, 4, 1, 6, -1, 1, 0, -1, -1, -1, 2, 8, 7, 7, -1, -1, 0, 2, 5, 5, 9, 3, 3, -1, 7, 6, 6, 7, 9, 8, 1, 7, 7, 7, 2, 6, -1, 7, -1, 4, 6, 4, 6, -1, -1, 9, 1, -1, -1, -1, 5, 5, 5, 4, 2, 2, 8, 5, 1, 1, 3, 1, 3, 7, -1, 2, -1, 9, 1, 4, 4, 7, 7, -1, 1, 5, 6, 2, 7, 3, -1, 9, 1, -1, 2, 4, 4, 8, -1, -1, 7, -1, 6, -1, 7, 4, 3, 5, 8, 4, 8, 5, -1, -1, 8, -1, -1, -1, 4, 4, -1, -1, -1, -1, 8, 3, 5, 5, -1, -1, -1, 1, 2, 0, -1, -1, 9, 3, -1, 8, 3, 7, 1, 8, 9, 0, 1, 8, 2, -1, 4, -1, -1, 8, -1, -1, -1, -1, 2, -1, 4, 8, 5, 5, 3, 1, -1, -1, 6, -1, 1, -1, -1, 6, -1, -1, -1, -1, 7, 3, -1, -1, -1, 8, 6, 4, -1, 6, 9, 0, 7, 8, -1, -1, 0, 6, 7, -1, -1, 0, 0, 7, 2, 3, 2, -1, 0, 2, 3, -1, 0, 1, 7, 9, 0, 7, -1, -1, -1, -1, 5, 8, 2, 6, 3, 2, 0, 4, -1, -1, 0, 9, 1, 1, 1, -1, 1, 3, -1, 7, 9, 1, 3, 3, 8, -1, -1, -1, -1, 6, -1, -1, -1, -1, 9, 8, 1, 3, 8, 3, 0, 6, -1, -1, 8, 5, 6, 5, 2, 1, -1, 5, -1, 7, 0, 0, -1, 9, 3, 9, -1, 3, 0, 0, 9, 1, 7, 0, 2, -1, 6, 8, 5, -1, -1, -1, -1, -1, 7, -1, 2, 5, -1, -1, 9, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 4, 1, -1, 3, 6, 6, 2, 5, 5, 9, -1, -1, 7, 8, -1, -1, 2, 7, 3, 7, 2, 5, -1, 1, 3, 4, -1, -1, 8, 3, 6, 9, -1, 1, -1, -1, -1, -1, 9, 7, 5, 2, -1, 5, -1, 6, 4, 5, -1, 1, 2, 0, 6, -1, 1, 6, -1, -1, 5, -1, 7, 8, 4, 7, 8, 6, 4, -1, 5, 6, 7, 9, 1, 0, 4, -1, -1, -1, 6, 4, 8, 4, 5, -1, 0, 4, 4, 0, 1, 7, 1, -1, 1, -1, 3, 6, -1, -1, -1, -1, 8, -1, 5, 0, 7, 5, -1, -1, 5, 8, -1, -1, 3, -1, -1, 8, -1, 2, 4, -1, -1, -1, -1, -1, -1, -1, 9, -1, 9, -1, 9, -1, -1, -1, -1, 7, 1, -1, -1, 2, -1, -1, 5, 5, 5, 5, 6, 4, -1, -1, 1, 6, 4, 0, -1, 0, 6, 3, 0, -1, 5, 5, -1, -1, -1, -1, 2, -1, 3, 6, -1, 3, 0, 5, 0, 1, 0, 3, 4, 9, 9, 2, 7, 3, 8, 6, 9, -1, 5, 8, -1, -1, -1, -1, 9, 8, 0, 7, -1, -1, 8, 8, 6, 6, 0, 2, 7, 4, 2, 3, 8, 6, 4, -1, 8, -1, -1, -1, 2, 0, -1, 1, 3, 5, 4, 2, 2, 5, 8, 8, -1, 3, 0, -1, 1, 6, 0, -1, -1, 9, -1, 2, -1, 6, 8, 2, -1, -1, 5, -1, -1, -1, 9, 6, 6, 4, 2, 0, -1, -1, 1, -1, 0, -1, -1, -1, 6, 6, -1, -1, -1, 4, 7, 9, -1, 0, 1, -1, -1, 9, -1, -1, -1, 4, -1, 8, -1, -1, -1, -1, -1, -1, 4, -1, 6, -1, 3, -1, -1, 5, 1, 2, 5, -1, 0, 7, 8, -1, 7, -1, -1, 4, -1, 4, 4, -1, 2, -1, 6, -1, -1, -1, 7, -1, -1, -1, -1, 6, 4, -1, 6, -1, 6, 9, -1, -1, -1, 9, 6, -1, 9, -1, 3, -1, 2, -1, 7, 7, -1, -1, 0, -1, 6, 3, -1, -1, -1, -1, -1, -1, 1, -1, -1, -1, 6, 9, 7, -1, 7, -1, 9, 3, 3, -1, -1, -1, -1, 4, -1, -1, 3, -1, -1, -1, 3, 9, -1, 0, 3, 1, 9, 6, 7, 9, 4, 8, -1, -1, 6, -1, 1, 3, 7, -1, -1, -1, 3, -1, 2, -1, 8, 1, 1, -1, -1, 6, -1, 7, 3, 5, -1, 6, 3, 4, -1, -1, 5, 7, 1, -1, -1, 6, 4, 6, -1, -1, -1, -1, 5, 7, 0, 7, 0, -1, 5, 8, 5, 5, 4, 5, -1, -1, -1, -1, -1, -1, 1, 7, -1, -1, 7, -1, 9, 9, 6, 4, -1, -1, 3, 2, 1, -1, 0, -1, 0, 6, -1, -1, -1, 1, 5, -1, -1, -1, 8, -1, -1, -1, -1, 3, 4, 8, -1, -1, 9, 6, 4, -1, -1, -1, -1, 8, 9, -1, 1, -1, -1, -1, 7, -1, -1, -1, -1, -1, 9, -1, -1, -1, 4, 1, 6, 7, 0, -1, -1, -1, 7, -1, -1, 8, -1, -1, -1, -1, -1, -1, -1, 4, -1, 9, -1, -1, -1, -1, 3, 0, 6, -1, 5, -1, 9, 9, -1, -1, 4, 3, 4, -1, -1, -1, -1, 8, -1, 5, -1, -1, -1, -1, 5, 2, -1, -1, -1, -1, -1, -1, -1, 2, -1, -1, 2, 1, 8, 5, -1, 0, -1, 0, 3, 2, 4, 5, -1, -1, -1, -1, -1, 7, -1, -1, 0, -1, 0, -1, -1, -1, 0, 3, 9, -1, -1, -1, -1, 5, -1, -1, 0, 5, 0, 0, -1, 9, -1, -1, -1, -1, -1, -1, -1, -1, 8, -1, 9, 3, 5, 9, 0, 5, 9, -1, -1, 9, 4, -1, 0, 2, 0, -1, -1, 7, -1, 7, -1, 5, 7, 8, 7, -1, -1, -1, 3, 0, 3, -1, -1, -1, -1, -1, 4, 5, -1, -1, 2, 3, -1, 2, -1, -1, 7, -1, -1, 9, -1, -1, 9, 7, 1, -1, -1, 1, 6, 1, 8, -1, -1, 5, -1, -1, 3, 7, 9, 6, -1, -1, -1, -1, 1, -1, -1, -1, 3, 7, 3, 2, 3, 3, -1, 1, -1, -1, -1, 1, -1, -1, 4, 3, 4, 8, 7, -1, 0, 3, 0, -1, 1, 1, -1, -1, -1, -1, -1, 5, -1, 6, 0, -1, 3, 1, -1, 6, -1, -1, 4, 0, 1, -1, 6, 1, -1, -1, 9, 6, 4, 9, 0, 8, 9, 3, 3, 6, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 2, -1, -1, -1, -1, -1, 8, 5, 8, 3, 5, 4, -1, 6, -1, 0, -1, -1, 6, -1, 4, 3, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 7, 3, -1, -1, 1, -1, 2, 4, -1, -1, -1, 6, -1, -1, -1, 6, -1, 5, -1, -1, -1, -1, 1, -1, -1, 3, -1, 1, -1, 7, 1, -1, -1, 7, 1, 3, 4, 8, -1, -1, -1, -1, -1, 4, -1, -1, 4, -1, -1, -1, 7, -1, 6, -1, -1, 1, -1, -1, -1, 7, 3, 3, -1, -1, -1, -1, 3, 0, -1, -1, 4, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 8, -1, -1, 9, -1, -1, 6, 6, 5, 2, -1, 8, 3, 8, -1, -1, -1, -1, 6, 7, 0, -1, -1, -1, -1, 1, 1, 5, -1, 0, 5, -1, 5, -1, -1, -1, 1, 2, -1, 2, 9, 1, -1, 2, 4, 1, -1, -1, -1, 1, 8, 4, 4, 5, 2, -1, -1, 6, 4, 7, 5, 2, 9, -1, 4, -1, -1, -1, -1, -1, 3, -1, -1, 5, 9, -1, -1, -1, -1, 9, -1, 9, -1, -1, -1, 2, -1, 1, 9, -1, -1, -1, -1, -1, 1, 9, 3, -1, -1, 1, 9, -1, 5, 2, 1, 0, -1, -1, 1, 9, 8, 4, 7, -1, -1, 5, 7, -1, -1, -1, -1, 1, 2, 8, -1, 6, 0, -1, -1, -1, -1, 0, -1, -1, -1, 6, -1, 2, 3, 0, 9, -1, -1, 1, 4, 6, -1, 8, -1, -1, 5, -1, 3, 0, -1, 6, -1, -1, -1, -1, -1, 2, -1, -1, -1, -1, -1, -1, 2, 5, 8, 6, 9, -1, -1, -1, 8, -1, -1, 9, 6, -1, -1, -1, -1, 3, -1, -1, -1, -1, 9, -1, -1, 2, -1, -1, -1, -1, -1, -1, 8, 8, -1, -1, -1, -1, -1, 9, -1, 6, -1, 2, 5, -1, -1, 1, 2, -1, 4, -1, -1, 4, -1, -1, 3, 5, -1, 3, 3, -1, -1, 1, -1, -1, -1, -1, 4, -1, 2, 3, -1, 4, 5, 3, -1, 7, -1, -1, -1, 7, 6, -1, -1, 1, 3, -1, 4, 9, 8, -1, -1, 0, -1, 3, 4, -1, 8, -1, 1, -1, -1, 2, 2, -1, -1, 4, -1, -1, -1, 3, -1, -1, 2, -1, -1, -1, 4, -1, 5, -1, -1, -1, -1, 2, -1, 5, -1, -1, -1, -1, -1, -1, 2, 7, 5, -1, 6, -1, -1, -1, -1, 2, -1, 0, -1, 3, -1, 1, -1, 9, 4, -1, 3, -1, -1, -1, -1, -1, -1, -1, 5, 5, 7, -1, -1, 1, -1, 4, 6, -1, -1, -1, 2, -1, 5, 9, 0, 6, 2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 5, -1, 7, -1, 2, 9, -1, -1, 1, -1, -1, -1, 1, 6, -1, 6, -1, -1, 0, 8, -1, 4, -1, -1, -1, -1, 4, -1, -1, 0, -1, 6, 0, -1, -1, -1, 4, -1, -1, -1, -1, -1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 5, 4, 2, 6, 4, 5, 3, 4, -1, -1, 5, -1, -1, -1, -1, 4, -1, -1, 3, 6, 2, 0, -1, 6, 6, -1, -1, -1, -1, 0, 6, -1, -1, -1, 3, 9, 4, -1, -1, -1, -1, -1, 0, -1, -1, 6, 7, 0, -1, 9, 2, -1, 3, 3, -1, -1, 8, -1, 3, -1, -1, -1, 8, 5, 3, -1, 2, 4, -1, 9, 6, 9, -1, -1, -1, -1, 6, -1, 6, -1, 5, 3, -1, -1, -1, -1, 4, -1, -1, -1, 9, 0, 9, 7, 1, 1, -1, 1, -1, 1, 6, -1, 5, -1, 6, -1, -1, 1, -1, -1, -1, -1, -1, -1, 5, -1, -1, -1, -1, -1, 3, -1, 6, 1, -1, 0, 2, -1, -1, 0, -1, -1, 0, -1, -1, -1, -1, -1, 3, -1, -1, 8, -1, -1, 5, 3, 3, -1, -1, -1, -1, -1, -1, -1, 3, -1, -1, 0, 8, 7, -1, -1, 8, 1, -1, -1, -1, -1, -1, -1, 7, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 5, 2, -1, 2, 6, -1, -1, -1, -1, -1, -1, -1, 1, 5, 0, -1, -1, 2, -1, 7, -1, -1, 6, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 8, -1, -1, -1, -1, 3, -1, -1, 4, -1, -1, 2, -1, -1, -1, -1, 0, 3, -1, -1, -1, -1, -1, 7, -1, 8, -1, -1, -1, -1, 8, 5, -1, 3, 4, -1, -1, -1, 8, -1, -1, -1, -1, -1, -1, -1, -1, -1, 3, 7, -1, -1, -1, 4, 0, 3, -1, -1, 6, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 8, -1, -1, -1, -1, -1, 2, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, -1, -1, -1, 2, -1, -1, -1, 8, 2, -1, -1, -1, -1, -1, -1, -1, 8, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 2, -1, -1, -1, 2, 5, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 2, -1, -1, -1, -1, -1, 8, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 5}), 1, 24));
    }

    /*
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        queue<TreeNode*> record;
        record.push(root);
        if (d == 1) {
            root = new TreeNode(v);
            root->left = record.front();
            return root;
        }
        while (!record.empty())
        {
            size_t n = record.size();
            if (--d == 1) {
                while (n--) {
                    auto &cur = record.front();
                    record.pop();
                    TreeNode* 
                    = new TreeNode(v);
                    new_left->left = cur->left;
                    cur->left = new_left;
                    TreeNode* new_right = new TreeNode(v);
                    new_right->right = cur->right;
                    cur->right = new_right;
                }
                break;
            } else {
                while (n--) {
                    auto &cur = record.front();
                    record.pop();
                    if (cur->left) record.push(cur->left);
                    if (cur->right) record.push(cur->right);
                }
            }
        }
        return root;
    }
    */
    TreeNode *addOneRow(TreeNode *root, int v, int d, bool isLeft = true)
    {
        if (d == 1)
        {
            TreeNode *left = isLeft ? root : nullptr, *right = isLeft ? nullptr : root;
            return new TreeNode(v, left, right);
        }

        if (root)
        {
            root->left = addOneRow(root->left, v, d - 1);
            root->right = addOneRow(root->right, v, d - 1, false);
        }
        return root;
    }
};