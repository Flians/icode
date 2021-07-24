#include "../base/icode.hpp"
class L199 : public icode
{
public:
    void run()
    {
        // [1,3,4]
        print_res(rightSideView(create_tree({1, 2, 3, INT_MIN, 5, INT_MIN, 4})));
    }

    vector<int> rightSideView(TreeNode *root)
    {
        queue<TreeNode *> level;
        vector<int> res;
        if (!root)
            return res;
        level.push(root);
        while (!level.empty())
        {
            size_t len = level.size();
            int tmp = 0;
            TreeNode *cur = NULL;
            while (len--)
            {
                cur = level.front();
                level.pop();
                tmp = cur->val;
                if (cur->left)
                {
                    level.push(cur->left);
                }
                if (cur->right)
                {
                    level.push(cur->right);
                }
            }
            res.push_back(tmp);
        }
        return res;
    }
};