#include "../base/icode.hpp"
class L897 : public icode
{
public:
	void run() {
        // [1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]
        print_res(increasingBST(create_tree<int, TreeNode>({5,3,6,2,4,-1,8,1,-1,-1,-1,7,9})));
    }

    void inorder(vector<TreeNode *> &nodes, TreeNode* root) {
        if (!root) return;
        inorder(nodes, root->left);
        nodes.push_back(root);
        inorder(nodes, root->right);
    }
    TreeNode* increasingBST(TreeNode* root) {
        if (root == NULL)
            return NULL;
        vector<TreeNode *> nodes;
        inorder(nodes, root);
        nodes[0]->left = NULL;
        for (size_t i = 1; i < nodes.size(); ++i) {
            nodes[i]->left = NULL;
            nodes[i-1]->right = nodes[i];
        }
        return nodes[0];
    }
};