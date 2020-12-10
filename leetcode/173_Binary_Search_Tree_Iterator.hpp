#include "../base/icode.hpp"
class BSTIterator : public icode {
private:
    size_t index;
    vector<int> vals;
    
public:
    BSTIterator() {}

    virtual ~BSTIterator(){};

    BSTIterator(TreeNode* root) {
        stack<TreeNode*> record;
        record.push(root);
        while (!record.empty()) {
            TreeNode* cur = record.top();
            record.pop();
            if (!cur) continue;
            while (cur->left) {
                record.push(cur);
                TreeNode* tmp = cur->left;
                cur->left = NULL;
                cur = tmp;
            }
            vals.push_back(cur->val);
            record.push(cur->right);
        }
        std::reverse(vals.begin(), vals.end());
        index = vals.size();
    }
    
    int next() {
        return vals[--index];
    }
    
    bool hasNext() {
        return index > 0;
    }

    void run() {
        vector<int> nums = {7, 3, 15, -1, -1, 9, 20};
        BSTIterator* obj = new BSTIterator(create_tree<int, TreeNode>(nums));
        cout << obj->next() << " 3" << endl;    // return 3
        cout << obj->next() << " 7" << endl;    // return 7
        cout << obj->hasNext() << " true" << endl; // return True
        cout << obj->next() << " 9" << endl;    // return 9
        cout << obj->hasNext() << " true" << endl; // return True
        cout << obj->next() << " 15" << endl;    // return 15
        cout << obj->hasNext() << " true" << endl; // return True
        cout << obj->next() << " 20" << endl;    // return 20
        cout << obj->hasNext() << " false" << endl; // return False
        delete obj;
    }
};
