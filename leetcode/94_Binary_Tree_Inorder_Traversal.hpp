#include "../base/icode.hpp"

class L94 : public icode {
public:
    void traversal_rec(TreeNode* root, vector<int> &res) {
        if (!root)
            return;
        traversal_rec(root->left, res);
        res.push_back(root->val);
        traversal_rec(root->right, res);
    }
    
    void traversal_ite(TreeNode* root, vector<int> &res) {
        stack<TreeNode *> record;
        TreeNode * cur = root;
        while (cur || !record.empty()) {
            while (cur) {
                record.push(cur);
                cur = cur->left;
            }
            cur = record.top();
            res.push_back(cur->val);
            cur = cur->right;
            record.pop();
        }
    }
    
    void traversal_changeTree(TreeNode* root, vector<int> &res) {
        TreeNode * pre;
        TreeNode * cur = root;
        while (cur) {
            if (cur->left==NULL) {
                res.push_back(cur->val);
                cur = cur->right;
            } else {
                pre = cur->left;
                while (pre->right) {
                    pre = pre->right;
                }
                pre->right = cur;
                TreeNode * temp = cur;
                cur = cur->left;
                temp->left = NULL;
            }
        }
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        traversal_changeTree(root, res);
        return res;
    }

    void run() {
        // input: [3,1,null,null,2], output: [1,2,3] 
    }
};