#include "../base/icode.hpp"

class L1028 : public icode {
public:
    int str_to_int(string S, int &index) {
        int res=0;
        while(index < (int)S.length() && S[index]!='-') {
            res *= 10;
            res += S[index++]-'0';
        }
        return res;
    }
    
    TreeNode* recoverFromPreorder(string S) {
        if (S.empty())
            return NULL;
        int index=0, level=0;
        stack<TreeNode *> record;
        TreeNode *root = new TreeNode(str_to_int(S, index));
        record.push(root);
        while (record.size() && index < (int)S.length()) {
            int temp = 0;
            while (index < (int)S.length() && S[index] == '-') {
                ++temp;
                ++index;
            }
            TreeNode *child = new TreeNode(str_to_int(S, index));
            if (temp > level) {
                record.top()->left = child;
            } else if (temp == level) {
                record.pop();
                record.top()->right = child;
            } else {
                while (temp <= (level--)) {
                    record.pop();
                }
                record.top()->right = child;
            }
            record.push(child);
            level = temp;
        }
        return root;
    }

    void run (){
        // [1,2,5,3,4,6,7]
        recoverFromPreorder("1-2--3--4-5--6--7");
        // [8,6,7,9,4,null,null,10]
        recoverFromPreorder("8-6--9---10--4-7");
    }
};