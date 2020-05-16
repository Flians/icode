#include "../base/icode.hpp"

class L230 : public icode {
public:
    void find_rec(TreeNode* root, vector<int>& nums, int k) {
        if (!root)
            return;
        find_rec(root->left, nums, k);
        nums.push_back(root->val);
        find_rec(root->right, nums, k);
    }
    int find_ite(TreeNode* root, int k) {
        stack<TreeNode*> record;
        while (root || !record.empty()) {
            while (root) {
                record.push(root);
                root = root->left;
            }
            root = record.top();
            record.pop();
            if ((--k)==0)
                return root->val;
            root = root->right;
        }
        return -1;
    }
    int kthSmallest(TreeNode* root, int k) {
        /*
        vector<int> nums;
        find_rec(root, nums, k);
        return nums[k-1];
        */
        return find_ite(root, k);
    }

    void run() {
        //Input: root = [5,3,6,2,4,null,null,1], k = 3. output: 3
    }
};