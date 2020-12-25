#include "../base/icode.hpp"
class L1305 : public icode
{
public:
	void run() {
        print_res(move(getAllElements(create_tree({2,1,4}), create_tree({1,0,3}))));
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