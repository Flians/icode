#include "../base/icode.h"

class L124 : public icode {
public:
    int maxPathSum(TreeNode* root) {
        if (!root)
            return 0;
        int sumP=root->val, ml=0, mr=0;
        if (root->left) {
            sumP = max(maxPathSum(root->left), sumP);
            ml = max(root->left->val, ml);
        }
        if (root->right) {
            sumP = max(maxPathSum(root->right), sumP);
            mr = max(root->right->val, mr);
        }
        sumP = max(root->val+ml+mr, sumP);
        root->val += max(ml, mr);
        return sumP;
    }

    void run() {
        /*
[5,4,8,11,null,13,4,7,2,null,null,null,1], 48
[-3], -3
        */
    }
};