#include "../base/icode.hpp"
class L572 : public icode
{
public:
	void run() {
        vector<int> A = {3,4,5,1,-1,2};
        vector<int> B = {3,1,2};
        cout << isSubtree(create_tree<int, TreeNode>(A), create_tree<int, TreeNode>(B)) << " false" << endl;
        A = {3,4,5,1,2,-1,-1,-1,6};
        B = {4,1,2};
        cout << isSubtree(create_tree<int, TreeNode>(A), create_tree<int, TreeNode>(B)) << " false" << endl;
        A = {3,4,5,1,2};
        B = {4,1,2};
        cout << isSubtree(create_tree<int, TreeNode>(A), create_tree<int, TreeNode>(B)) << " true" << endl;
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