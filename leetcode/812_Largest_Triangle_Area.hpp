#include "../base/icode.hpp"

class L812 : public icode 
{
public:
    double largestTriangleArea(vector<vector<int>> &points)
    {
        int n = points.size();
        double res_max = 0.0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    double area = 0.5 * fabs(points[i][0] * points[j][1] +
                                             points[j][0] * points[k][1] +
                                             points[k][0] * points[i][1] -
                                             points[i][1] * points[j][0] -
                                             points[j][1] * points[k][0] -
                                             points[k][1] * points[i][0]);
                    res_max = max(res_max, area);
                }
            }
        }
        return res_max;
    }
    void run()
    {
        vector<vector<int>> points = {{0,0},{0,1},{1,0},{0,2},{2,0}};
        cout << largestTriangleArea(points) << endl;
    }
};