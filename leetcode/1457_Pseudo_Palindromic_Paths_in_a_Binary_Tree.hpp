#include "../base/icode.hpp"
class L1457 : public icode
{
public:
    void run()
    {
        cout << pseudoPalindromicPaths(create_tree<TreeNode>({9})) << " 1" << endl;
        cout << pseudoPalindromicPaths(create_tree<TreeNode>({2, 3, 1, 3, 1, INT_MIN, 1})) << " 2" << endl;
    }

    void dfs(TreeNode *root, vector<int> nums, int &res)
    {
        if (!root)
        {
            return;
        }
        ++nums[root->val];
        if (root->left)
            dfs(root->left, nums, res);
        if (root->right)
            dfs(root->right, nums, res);
        if (!root->left && !root->right)
        {
            int odd = 0;
            for (int i = 1; i <= 9; ++i)
            {
                if (nums[i] % 2 == 1)
                    ++odd;
            }
            if (odd <= 1)
                ++res;
        }
    }
    int pseudoPalindromicPaths(TreeNode *root)
    {
        int res = 0;
        dfs(root, vector<int>(10, 0), res);
        return res;
    }
};