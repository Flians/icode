#include "../base/icode.hpp"
class L235 : public icode
{
public:
	void run() {
        TreeNode* p = new TreeNode(2);
        TreeNode* q = new TreeNode(4);
        cout << lowestCommonAncestor(create_tree({6,2,8,0,4,7,9,INT_MIN,INT_MIN,3,5}), p, q)->val << " 2" << endl;
        delete p;
        delete q;
    }

    TreeNode* inorder (TreeNode *root, int minv, int maxv) {
        if (root->val < minv) {
            return inorder(root->right, minv, maxv);
        } else if (root->val > maxv) {
            return inorder(root->left, minv, maxv);
        } else {
            return root;
        }
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int minv = min(p->val, q->val);
        int maxv = max(p->val, q->val);
        return inorder(root, minv, maxv);
    }
};