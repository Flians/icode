#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int T, W, H, L, U, R, D;

bool check(int x, int y)
{
    return x >= L && y >= U && x <= R && y <= D;
}

int main()
{
    int i, j, index = 1;
    cin >> T;
    while (T--)
    {
        cin >> W >> H >> L >> U >> R >> D;
        double holes = 0;
        vector<double> area(W + 1, 0);
        area[0] = 2;
        for (i = 1; i <= H; ++i)
        {
            for (j = 1; j <= W; ++j)
            {
                if (check(j, i))
                {
                    if (j == W)
                    {
                        holes += area[j - 1] * 0.5 + area[j];
                    }
                    else if (i == H)
                    {
                        holes += area[j - 1] + area[j] * 0.5;
                    }
                    else
                    {
                        holes += area[j - 1] * 0.5 + area[j] * 0.5;
                    }
                    area[j] = 0;
                }
                else
                {
                    if (j==W && i==H) {
                        area[j] = area[j - 1] + area[j];
                    }else if (j == W)
                    {
                        area[j] = area[j - 1] * 0.5 + area[j];
                    }
                    else if (i == H)
                    {
                        area[j] = area[j - 1] + area[j] * 0.5;
                    }
                    else
                    {
                        area[j] = area[j - 1] * 0.5 + area[j] * 0.5;
                    }
                }
            }
            area[0] = 0;
        }
        cout << "Case #" << (index++) << ": " << double(area[W]) / (area[W] + holes) << endl;
    }
    return 0;
}