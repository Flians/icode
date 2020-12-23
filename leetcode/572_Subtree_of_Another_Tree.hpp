#include "../base/icode.hpp"
class L572 : public icode
{
public:
	void run() {
        cout << isSubtree(create_tree<int, TreeNode>({3,4,5,1,INT_MIN,2}), create_tree<int, TreeNode>({3,1,2})) << " false" << endl;
        cout << isSubtree(create_tree<int, TreeNode>({3,4,5,1,2,INT_MIN,INT_MIN,INT_MIN,6}), create_tree<int, TreeNode>({4,1,2})) << " false" << endl;
        cout << isSubtree(create_tree<int, TreeNode>({3,4,5,1,2}), create_tree<int, TreeNode>({4,1,2})) << " true" << endl;
    }

    bool equals(TreeNode *x, TreeNode *y)
    {
        if(!x && !y)
            return true;
        if(!x || !y)
            return false;
        return x->val==y->val && equals(x->left, y->left) && equals(x->right, y->right);
    }
    
    bool isSubtree(TreeNode* A, TreeNode* B) {
        if (!A || !B) {
            return false;
        }
        return equals(A, B) || isSubtree(A->left, B) || isSubtree(A->right, B);
    }
};