#include "../base/icode.h"

class L1008 : public icode
{
public:
    TreeNode *create(vector<int> &preorder, int left, int right)
    {
        if (left > right)
            return NULL;
        int i;
        TreeNode *root = new TreeNode(preorder[left]);
        for (i = left + 1; i <= right; i++)
        {
            if (preorder[i] > preorder[left])
            {
                root->right = create(preorder, i, right);
                break;
            }
        }
        root->left = create(preorder, left + 1, i - 1);
        return root;
    }

    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        return create(preorder, 0, preorder.size() - 1);
    }

    /*
     Input: [8,5,1,7,10,12]
     Output: [8,5,10,1,7,null,12]
    */
    void run() {
        vector<int> a = {8,5,1,7,10,12};
        bstFromPreorder(a);
    }
};