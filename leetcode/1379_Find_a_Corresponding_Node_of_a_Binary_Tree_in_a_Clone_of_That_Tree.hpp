#include "../base/icode.hpp"
class L1379 : public icode
{
public:
	void run() {
        TreeNode *original = create_tree<TreeNode>({7,4,3,-1,-1,6,19});
        cout << getTargetCopy(original, create_tree<TreeNode>({7,4,3,-1,-1,6,19}), original->right)->val << " 3" << endl;
    }

    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if (!original || !cloned) return NULL;
        if (original == target) {
            return cloned;
        }
        TreeNode *left = getTargetCopy(original->left, cloned->left, target);
        TreeNode *right = getTargetCopy(original->right, cloned->right, target);
        return left?left:right?right:NULL;
    }
};