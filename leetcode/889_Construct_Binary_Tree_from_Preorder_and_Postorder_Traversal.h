#include "../base/icode.h"
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class L889 : public icode {
public:
    TreeNode* construct(int prl, int prr, vector<int>& pre, int pol, int por, vector<int>& post) {
        if (prl > prr || pol > por)
            return NULL;
        TreeNode* root = new TreeNode(pre[prl]);
        if (pre[prl] != post[por])
            cout << "there are some wrong!" << endl;
        int tc=0;
        if (prl<prr) {
            for (tc=pol; tc<por; ++tc) {
                if (pre[prl+1] == post[tc])
                    break;
            }
            if (tc == por)
                cout << "there are some wrong!" << endl;
            root->left = construct(prl+1, prl+tc-pol+1, pre, pol, tc, post);
            root->right = construct(prl+tc-pol+2, prr, pre, tc+1, por-1, post);
        }
        return root;
    }
    
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        return construct(0, pre.size()-1, pre, 0, post.size()-1, post);
    }

    void run() {
        /*
        Input: pre = [1,2,4,5,3,6,7], post = [4,5,2,6,7,3,1]
        Output: [1,2,3,4,5,6,7]
        */
    }
};