#include "../base/icode.hpp"

class Solution_ : public icode {
public:
    bool isValidSequence(TreeNode* root, vector<int>& arr, int index=0) {
        if (!root)
            return arr.size() <= index;
        if (arr.size() <= index)
            return root?false:true;
        bool flag = false;
        if (root->val == arr[index++]) {
            if (index==arr.size()) {
                flag = !root->left && !root->right;
            } else {
                if (isValidSequence(root->left, arr, index))
                    flag = true;
                if (isValidSequence(root->right, arr, index))
                    flag = true;
            }
        }
        return flag;
    }

    void run() {
        /*
[3,0,null,2,null,null,2,9,3], [3], false
[3,0,null,2,null,null,2,9,3], [3,0], false
[0,1,0,0,1,0,null,null,1,0,0], [0,1,0,1], true
        */
    }
};