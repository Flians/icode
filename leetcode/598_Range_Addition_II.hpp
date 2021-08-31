#include "../base/icode.hpp"
class L598 : public icode
{
public:
    void run()
    {
        cout << maxCount(3, 3, {{2, 2}, {3, 3}}) << " 4" << endl;
    }

    int maxCount(int m, int n, vector<vector<int>> &&ops)
    {
        int min_row = m;
        int min_col = n;
        for (int i = 0, num = ops.size(); i < num; i++)
        {
            if (ops[i][0] < min_row)
                min_row = ops[i][0];
            if (ops[i][1] < min_col)
                min_col = ops[i][1];
        }
        return min_row * min_col;
    }
};