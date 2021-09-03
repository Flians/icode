#include "../base/icode.hpp"
class L95 : public icode
{
public:
    void run()
    {
        // [[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]
        bool flag = 0;
        std::cout << "[\n";
        for (auto &item : generateTrees(3))
        {
            if (flag)
                std::cout << ", ";
            flag = 1;
            print_res(item);
        }
        std::cout << "]" << std::endl;
    }

    vector<TreeNode *> generateTrees(int n, int s = 1)
    {
        vector<TreeNode *> ans;
        if (n < s)
            return {nullptr};
        for (int i = s; i <= n; i++)
        {
            for (auto left : generateTrees(i - 1, s))
            {
                for (auto right : generateTrees(n, i + 1))
                    ans.emplace_back(new TreeNode(i, left, right));
            }
        }
        return ans;
    }
};