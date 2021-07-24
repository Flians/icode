#include "../base/icode.hpp"
class L1302 : public icode
{
public:
    void run()
    {
        std::cout << deepestLeavesSum(create_tree({1, 2, 3, 4, 5, INT_MIN, 6, 7, INT_MIN, INT_MIN, INT_MIN, INT_MIN, 8})) << " 15" << std::endl;
    }

    int deepestLeavesSum(TreeNode *root)
    {
        if (!root)
            return 0;
        queue<TreeNode *> level;
        level.push(root);
        int res = 0;
        while (!level.empty())
        {
            res = 0;
            std::size_t n = level.size();
            while (n--)
            {
                TreeNode *cur = level.front();
                level.pop();
                res += cur->val;
                if (cur->left)
                    level.push(cur->left);
                if (cur->right)
                    level.push(cur->right);
            }
        }
        return res;
    }
};