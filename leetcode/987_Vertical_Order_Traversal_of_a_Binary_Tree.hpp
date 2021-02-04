#include "../base/icode.hpp"
class L987 : public icode
{
public:
    void run()
    {
        // [[0],[1],[3,2,2],[4]]
        print_res(verticalTraversal_new(create_tree<TreeNode>({3, 1, 4, 0, 2, 2})));
    }

    void rec(TreeNode *cur, int hd, int height, map<int, vector<pair<int, int>>> &m)
    {
        m[hd].push_back({(cur->val), height});

        if (cur->left != nullptr)
        {
            rec(cur->left, hd - 1, height + 1, m);
        }

        if (cur->right != nullptr)
        {
            rec(cur->right, hd + 1, height + 1, m);
        }
    }

    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        map<int, vector<pair<int, int>>> m;
        rec(root, 0, 0, m);
        vector<vector<int>> res;
        for (auto it : m)
        {
            sort(it.second.begin(), it.second.end(), [&](pair<int, int> &a, pair<int, int> &b) {
                return a.second == b.second ? a.first < b.first : a.second < b.second;
            });
            vector<int> item;
            for (auto it1 : it.second)
            {
                item.push_back(it1.first);
            }
            res.push_back(item);
        }
        return res;
    }

    vector<vector<int>> verticalTraversal_new(TreeNode *root)
    {
        std::queue<std::pair<TreeNode *, int>> level;
        std::map<int, std::vector<int>> maps;
        level.emplace(root, 0);
        while (!level.empty())
        {
            std::size_t len = level.size();
            std::map<int, std::vector<int>> line;
            while (len--)
            {
                auto cur = level.front();
                level.pop();
                if (line.find(cur.second) == line.end())
                {
                    line[cur.second] = std::vector<int>();
                }
                line[cur.second].push_back(cur.first->val);
                if (cur.first->left)
                {
                    level.emplace(cur.first->left, cur.second - 1);
                }
                if (cur.first->right)
                {
                    level.emplace(cur.first->right, cur.second + 1);
                }
            }
            for (auto &item : line)
            {
                sort(item.second.begin(), item.second.end());
                if (maps.find(item.first) == maps.end())
                {
                    maps[item.first] = std::move(item.second);
                }
                else
                {
                    maps[item.first].insert(maps[item.first].end(), item.second.begin(), item.second.end());
                }
            }
        }
        std::vector<std::vector<int>> res;
        for (auto &item : maps)
        {
            res.push_back(item.second);
        }
        return res;
    }
};