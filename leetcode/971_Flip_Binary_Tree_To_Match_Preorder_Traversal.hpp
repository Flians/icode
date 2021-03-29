#include "../base/icode.hpp"

class L971 : public icode
{
public:
    void run()
    {
        // [1]
        print_res(flipMatchVoyage(create_tree({1, 2, 3}), {1, 3, 2}));
    }

    vector<int> flipMatchVoyage(TreeNode *root, vector<int> &&voyage)
    {
        int i = 0;
        vector<int> res;
        stack<TreeNode *> sta;
        sta.push(root);
        while (!sta.empty())
        {
            TreeNode *cur = sta.top();
            sta.pop();
            if (!cur)
                continue;
            if (cur->val != voyage[i++])
                return {-1};
            if (cur->left && cur->left->val != voyage[i])
            {
                if (cur->right)
                    res.push_back(cur->val);
                sta.push(cur->left);
                sta.push(cur->right);
            }
            else
            {
                sta.push(cur->right);
                sta.push(cur->left);
            }
        }
        return res;
    }
};