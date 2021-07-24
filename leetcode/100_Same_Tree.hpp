#include "../base/icode.hpp"
class L100 : public icode
{
public:
    void run()
    {
        std::cout << isSameTree(create_tree({1, 2, 3, INT_MIN, INT_MIN, 4, 5}), create_tree({1, 2, 3})) << " False" << std::endl;
    }

    bool isSameTree(TreeNode *A, TreeNode *B)
    {
        if (!A && !B)
            return true;
        if (!A || !B)
            return false;
        return A->val == B->val && isSameTree(A->left, B->left) && isSameTree(A->right, B->right);
    }
};