#include "../base/icode.hpp"
class L1382 : public icode
{
public:
	void run() {
        // [2,1,3,null,null,null,4]
        print_res(balanceBST(create_tree<int, TreeNode>({1,-1,2,-1,3,-1,4,-1,-1})));
    }

    void inorder(TreeNode* root, vector<TreeNode*>& nodes) {
        if (!root) return;
        inorder(root->left, nodes);
        nodes.push_back(root);
        inorder(root->right, nodes);
    }
    
    TreeNode* preorder(vector<TreeNode*>& nodes, int l, int r) {
        if (l > r) return NULL;
        int mid = (l+r)/2;
        TreeNode* root = nodes[mid];
        root->left = preorder(nodes, l, mid - 1);
        root->right = preorder(nodes, mid + 1, r);
        return root;
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*> nodes;
        inorder(root, nodes);
        return preorder(nodes, 0, nodes.size()-1);
    }
};