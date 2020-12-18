#include "../base/icode.hpp"
class L450 : public icode
{
public:
	void run() {
        print_res(deleteNode(create_tree<int, TreeNode>({5,3,6,2,4,-1,7}), 3)); // [5,4,6,2,null,null,7]
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root)
            return root;
        if (root->val == key) {
            if (root->left) {
                if (root->right) {
                    if (root->left->right) {
                        TreeNode *tmp = root->right;
                        while (tmp->left) {
                            tmp = tmp->left;
                        }
                        tmp->left = root->left->right;
                    } 
                    root->left->right = root->right;
                }
                return root->left;
            }
            return root->right;
        } else if (root->val > key) {
            root->left = deleteNode(root->left, key);
        } else {
            root->right = deleteNode(root->right, key);
        }
        return root;
    }
};