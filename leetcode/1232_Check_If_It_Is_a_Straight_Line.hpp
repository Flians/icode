#include "../base/icode.hpp"
class L1232 : public icode
{
public:
    bool checkStraightLine(vector<vector<int>> &coordinates)
    {
        if ((int)coordinates.size() < 2)
            return false;
        int dy = coordinates[1][1] - coordinates[0][1];
        int dx = coordinates[1][0] - coordinates[0][0];
        for (int i = 2; i < (int)coordinates.size(); ++i)
        {
            if (dy * (coordinates[i][0] - coordinates[i - 1][0]) != dx * (coordinates[i][1] - coordinates[i - 1][1]))
                return false;
        }
        return true;
    }

    void run()
    {
        vector<vector<int>> coordinates = {{-3, -2}, {-1, -2}, {2, -2}, {-2, -2}, {0, -2}};
        cout << checkStraightLine(coordinates) << endl;
    }
};