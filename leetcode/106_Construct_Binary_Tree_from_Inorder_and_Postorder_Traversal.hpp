#include "../base/icode.hpp"

class L106 : public icode {
public:
    TreeNode* build(int iroot, vector<int>& postorder, int ileft, int iright, vector<int>& inorder) {
        if (iroot < 0 || ileft > iright)
            return NULL;
        TreeNode *root = new TreeNode(postorder[iroot]);
        int tc=ileft;
        for (; tc<=iright; ++tc) {
            if (inorder[tc] == postorder[iroot])
                break;
        }
        if (tc>iright)
            cout << "there are some errors!" << endl;
        root->left = build(iroot-1-(iright-tc), postorder, ileft, tc-1, inorder);
        root->right = build(iroot-1, postorder, tc+1, iright, inorder);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(postorder.size()-1, postorder, 0, inorder.size()-1, inorder);
    }

        void run() {
        /*
        inorder = [9,3,15,20,7]
        postorder = [9,15,7,20,3]
        [3,9,20,null,null,15,7]
        */
    }
};