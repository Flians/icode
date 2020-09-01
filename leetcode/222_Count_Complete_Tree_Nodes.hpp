#include "../base/icode.hpp"
class L222 : public icode
{
public:
	void run() {
        vector<int> nums = {1,2,3,4,5,6};
        TreeNode *root = create_tree(nums);
        cout << countNodes(root) << " 6" << endl;
    }

    void inorder(TreeNode* root, int &res) {
        if (root) {
            inorder(root->left, res);
            ++res;
            inorder(root->right, res);
        }
    }
    
    int countNodes(TreeNode* root) {
        int res = 0;
        inorder(root, res);
        return res;
    }
};