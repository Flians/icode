#include "../base/icode.hpp"
class L129 : public icode
{
public:
	void run() {
        cout << sumNumbers(create_tree<int, TreeNode>({4,9,0,5,1})) << " 1026" << endl;
    }

    void sumNumbers(TreeNode* root, int cur, int &all) {
        if (!root)
            return;
        cur *= 10;
        cur += root->val;
        if (root->left) {
            sumNumbers(root->left, cur, all);
        }
        if (root->right) {
            sumNumbers(root->right, cur, all);
        }
        if (!root->left && !root->right) {
            all += cur;
        }
    }
    
    int sumNumbers(TreeNode* root) {
        int res = 0;
        sumNumbers(root, 0, res);
        return res;
    }
};