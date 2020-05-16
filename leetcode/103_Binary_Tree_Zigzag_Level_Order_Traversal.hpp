#include "../base/icode.hpp"
class L103 : public icode {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root)
            return res;
        deque<TreeNode *> record;
        record.push_back(root);
        int len = 0;
        bool flag = true;
        while ((len=record.size()) > 0) {
            vector<int> layer;
            while (len--) {            
                if (flag) {
                    TreeNode* temp = record.front();
                    layer.push_back(temp->val);
                    if (temp->left)
                        record.push_back(temp->left);
                    if (temp->right)
                        record.push_back(temp->right);
                    record.pop_front();
                } else {
                    TreeNode* temp = record.back();
                    layer.push_back(temp->val);
                    if (temp->right)
                        record.push_front(temp->right);
                    if (temp->left)
                        record.push_front(temp->left);
                    record.pop_back();
                }
            }
            flag = !flag;
            res.push_back(layer);
        }
        return res;
    }

    void run() {
        /*
            [3,9,20,null,null,15,7] -> [[3],[20,9],[15,7]]
            [1,2,3,4,null,null,5] -> [[1],[3,2],[4,5]]
        */
    }
};