#include "../base/icode.hpp"
class L637 : public icode
{
public:
    void run()
    {
        print_res(averageOfLevels(create_tree({970, 953, INT_MIN, 945, INT_MIN, 944, INT_MIN, 928, INT_MIN, 793, INT_MIN, 892, INT_MIN, 887, INT_MIN, 887, INT_MIN, 878, INT_MIN, 852, INT_MIN, 837, INT_MIN, 830, 844, 828, INT_MIN, INT_MIN, INT_MIN, 818, INT_MIN, 898, INT_MIN, 775, INT_MIN, 774, INT_MIN, 725, INT_MIN, 685, INT_MIN, 673, INT_MIN, 646, INT_MIN, 598, INT_MIN, 583, INT_MIN, 531, INT_MIN, 516, INT_MIN, 511, INT_MIN, 431, 512, 429, 476, INT_MIN, INT_MIN, 427, INT_MIN, INT_MIN, INT_MIN, 404, INT_MIN, 367, INT_MIN, 325, INT_MIN, 323, INT_MIN, -406, INT_MIN, 285, INT_MIN, 258, INT_MIN, 230, INT_MIN, 229, INT_MIN, 205, INT_MIN, 163, INT_MIN, 144, INT_MIN, 106, INT_MIN, 96, INT_MIN, 80, INT_MIN, 71, INT_MIN, 50, INT_MIN, -20, INT_MIN, -51, INT_MIN, -62, INT_MIN, -67, INT_MIN, -70, INT_MIN, -125, INT_MIN, -152, INT_MIN, -156, INT_MIN, -164, INT_MIN, -191, INT_MIN, -203, INT_MIN, -224, INT_MIN, -251, INT_MIN, -278, INT_MIN, -279, INT_MIN, -332, INT_MIN, -371, INT_MIN, 297, INT_MIN, -422, INT_MIN, -425, INT_MIN, -433, INT_MIN, -440, INT_MIN, -446, INT_MIN, -672, INT_MIN, -504, INT_MIN, -534, INT_MIN, -549, INT_MIN, -553, INT_MIN, -566, INT_MIN, -832, INT_MIN, -606, INT_MIN, -609, INT_MIN, -617, INT_MIN, -650, INT_MIN, -656, INT_MIN, -663, INT_MIN, -488, INT_MIN, -675, INT_MIN, -697, INT_MIN, -703, INT_MIN, -718, INT_MIN, -730, INT_MIN, -731, INT_MIN, -747, INT_MIN, -765, INT_MIN, -807, INT_MIN, -819, INT_MIN, -591, INT_MIN, -899, INT_MIN, -907})));
    }

    vector<double> averageOfLevels(TreeNode *root)
    {
        std::vector<double> avg;
        std::queue<TreeNode *> record;
        record.push(root);
        while (!record.empty())
        {
            std::size_t n = record.size();
            std::size_t tmp = n;
            double item = 0;
            while (tmp--)
            {
                TreeNode *cur = record.front();
                record.pop();
                item += cur->val;
                if (cur->left)
                    record.push(cur->left);
                if (cur->right)
                    record.push(cur->right);
            }
            avg.push_back(item / n);
        }
        return avg;
    }
};