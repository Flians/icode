#include "../base/icode.hpp"
class L240 : public icode
{
public:
    void run()
    {
        cout << searchMatrix({{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}}, 5) << " true" << endl;
        cout << searchMatrix({{-5}}, -10) << " false" << endl;
    }

    bool searchMatrix(vector<vector<int>> &&matrix, int target)
    {
        for (size_t i = 0, n = matrix.size(); i < n; ++i)
        {
            for (int j = matrix[i].size() - 1; j >= 0 && i < n; --j)
            {
                if (matrix[i][j] < target)
                {
                    ++i;
                    ++j;
                }
                else if (matrix[i][j] == target)
                {
                    return true;
                }
            }
        }
        return false;
    }
};