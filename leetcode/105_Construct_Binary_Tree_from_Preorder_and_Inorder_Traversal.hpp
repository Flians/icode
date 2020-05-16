#include "../base/icode.hpp"

class L105: public icode {
public:
    TreeNode* build(int iroot, vector<int>& preorder, int ileft, int iright, vector<int>& inorder) {
        if (iroot >= (int)preorder.size() || ileft > iright)
            return NULL;
        TreeNode *root = new TreeNode(preorder[iroot]);
        int tc=ileft;
        for (; tc<=iright; ++tc) {
            if (inorder[tc] == preorder[iroot])
                break;
        }
        if (tc>iright)
            cout << "there are some errors!" << endl;
        root->left = build(iroot+1, preorder, ileft, tc-1, inorder);
        root->right = build(iroot+1+tc-ileft, preorder, tc+1, iright, inorder);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(0, preorder, 0, inorder.size()-1, inorder);
    }

    void run() {
        /*
        preorder = [3,9,20,15,7]
        inorder = [9,3,15,20,7]
        [3,9,20,null,null,15,7]
        */
    }
};