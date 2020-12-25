#include "../base/icode.hpp"
class L107 : public icode
{
public:
	void run() {
        // [[15,7],[9,20],[3]]
        print_res(levelOrderBottom(create_tree({3,9,20,INT_MIN,INT_MIN,15,7})));
    }

    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if (root == NULL)
            return res;
        queue<TreeNode *> record;
        record.push(root);
        while (!record.empty()) {
            int len = record.size();
            vector<int> level(len, 0);
            for (int i = 0; i < len; ++i){
                TreeNode* cur = record.front();
                record.pop();
                level[i] = cur->val;
                if (cur->left != NULL) record.push(cur->left);
                if (cur->right != NULL) record.push(cur->right);
            }
            res.insert(res.begin(), level);
        }
        return res;
    }
};