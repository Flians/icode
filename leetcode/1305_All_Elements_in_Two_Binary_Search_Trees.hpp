#include "../base/icode.hpp"
class L1305 : public icode
{
public:
	void run() {
        vector<int> root1 = {2,1,4}, root2 = {1,0,3};
        print_res(getAllElements(create_tree(root1), create_tree(root2)));
    }

    void inorder(TreeNode *root, vector<int> &res) {
        if (!root)
            return;
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> res;
        inorder(root1, res);
        inorder(root2, res);
        sort(res.begin(), res.end());
        return res;
    }
};