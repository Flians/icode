#include "../base/icode.hpp"
class L270 : public icode
{
public:
	void run() {
        // Input: root = [4,2,5,1,3], target = 3.714286
        // Output: 4
    }

    int closestValue(TreeNode* root, double target) {
        int res = root->val;
        while (root) {
            if (abs(res - target) >= abs(root->val - target)) {
                res = root->val;
            }
            root = target < root->val ? root->left : root->right;
        }
        return res;
    }
};