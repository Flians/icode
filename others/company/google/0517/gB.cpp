#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int T, R, C;

void do_color(int ri, int ci, char color, vector<vector<char>> &X)
{
    if (ri >= R || ci >= C || ri < 0 || ci < 0)
        return;
    if (X[ri][ci] == color)
    {
        if (ri == R - 1 || X[ri + 1][ci] == -1)
        {
            // cout << ri << " " << ci << " " << color << endl;
            X[ri][ci] = -1;
            do_color(ri + 1, ci, color, X);
            do_color(ri - 1, ci, color, X);
            do_color(ri, ci + 1, color, X);
            do_color(ri, ci - 1, color, X);
        }
    }
}

int main()
{
    int i, j, index = 1;
    cin >> T;
    while (T--)
    {
        cin >> R >> C;
        vector<vector<char>> X(R, vector<char>(C, 'A'));
        string line;
        for (i = 0; i < R; ++i)
        {
            cin >> line;
            for (j = 0; j < C; ++j)
                X[i][j] = line[j];
        }
        vector<vector<char>> Y = X;
        line = "";
        bool flag = false;
        for (i = R - 1; i >= 0; --i)
        {
            for (j = 0; j < C; ++j)
            {
                char temp = X[i][j];
                if (X[i][j] != -1)
                {
                    if (line.find(temp) != line.npos)
                    {
                        flag = true;
                        break;
                    }
                    do_color(i, j, temp, X);
                    line += temp;
                }
            }
            if (flag)
            {
                line = "-1";
                break;
            }
        }
        if (flag)
        {
            flag = false;
            line = "";
            for (i = R - 1; i >= 0; --i)
            {
                bool flag = false;
                for (j = C-1; j >= 0; --j)
                {
                    char temp = Y[i][j];
                    if (Y[i][j] != -1)
                    {
                        if (line.find(temp) != line.npos)
                        {
                            flag = true;
                            break;
                        }
                        do_color(i, j, temp, Y);
                        line += temp;
                    }
                }
                if (flag)
                {
                    line = "-1";
                    break;
                }
            }
        }
        cout << "Case #" << (index++) << ": " << line << endl;
    }
    return 0;
}