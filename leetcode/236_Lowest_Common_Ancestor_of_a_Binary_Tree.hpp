#include "../base/icode.hpp"
class L236 : public icode
{
private:
    TreeNode* res = NULL;
public:
	void run() {
        TreeNode* p = new TreeNode(5);
        TreeNode* q = new TreeNode(4);
        cout << lowestCommonAncestor(create_tree<int, TreeNode>({3,5,1,6,2,0,8,-1,-1,7,4}), p, q)->val << " 5" << endl;
    }
    
    TreeNode* inorder (TreeNode *root, int minv, int maxv) {
            if (!root)
                return NULL;
            int flag = 0;
            if (inorder(root->right, minv, maxv))
                ++flag;
            if (inorder(root->left, minv, maxv))
                ++flag;
            if (root->val == minv || root->val == maxv)
                ++flag;
            if (flag >= 2)
                res = root;
            return flag >= 1 ? root : NULL;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int minv = min(p->val, q->val);
        int maxv = max(p->val, q->val);
        inorder(root, minv, maxv);
        return res;
    }
};