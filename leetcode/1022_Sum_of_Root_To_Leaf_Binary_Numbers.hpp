#include "../base/icode.hpp"
class L1022 : public icode
{
public:
	void run() {
        vector<int> nums ={1,0,1,0,1,0,1};
        cout << sumRootToLeaf(create_tree<int, TreeNode>(nums)) << " 22" << endl;
    }

    void sumRootToLeaf(TreeNode* root, int cur, int &all) {
        if (!root) {
            all += cur;
            return;
        }
        cur *= 2;
        cur += root->val;
        if (root->left) {
            sumRootToLeaf(root->left, cur, all);
        }
        if (root->right) {
            sumRootToLeaf(root->right, cur, all);
        } 
        if (!root->left && !root->right) {
            all += cur;
            return;
        }
        
    }
    
    int sumRootToLeaf(TreeNode* root) {
        int res = 0;
        sumRootToLeaf(root, 0, res);
        return res;
    }
};