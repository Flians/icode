#include "../base/icode.h"
class L993 : public icode {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*> record;
        record.push(root);
        int len=0;
        while(!record.empty()) {
            int flag=0;
            len = record.size();
            while (len--) {
                int ft=0;
                TreeNode* temp = record.front();
                if (temp->left) {
                    record.push(temp->left);
                    if (temp->left->val == x || temp->left->val == y) {
                        ++flag;
                        ++ft;
                    }
                }
                if (temp->right) {
                    record.push(temp->right);
                    if (temp->right->val == x || temp->right->val == y) {
                        ++flag;
                        ++ft;
                    }
                }
                record.pop();
                if (ft == 2)
                    return false;
            }
            if (flag==2)
                return true;
            else if (flag==1)
                return false;
        }
        return false;
    }

    void run() {
     /*
Input: root = [1,2,3,4], x = 4, y = 3
Output: false

Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
Output: true
     */   
    }
};