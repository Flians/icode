/*
4 4
#S..
E#..
#...
....
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, minT;
int si, sj, ei, ej;

void fun(int i, int j, int cost, int num, vector<vector<int>> re, vector<vector<int>> dp)
{
    if (i < 0 || j < 0 || i >= n || j >= m || re[i][j] == -1 || dp[i][j] <= cost)
        return;
    if (i == ei && j == ej)
    {
        minT = min(minT, cost);
        return;
    }
    if (dp[i][j] > cost)
        dp[i][j] = cost;
    cost++;
    fun(i - 1, j, cost, num, re, dp);
    fun(i + 1, j, cost, num, re, dp);
    fun(i, j - 1, cost, num, re, dp);
    fun(i, j + 1, cost, num, re, dp);
    if (num < 5)
        fun(n - i - 1, m - j - 1, cost, num + 1, re, dp);
}

int main()
{
    int i, j;
    cin >> n >> m;
    minT = m * n;
    string line;
    vector<vector<int> > re(n, vector<int>(m, 0));
    for (i = 0; i < n; ++i)
    {
        cin >> line;
        for (j = 0; j < m; ++j)
        {
            switch (line[j])
            {
            case '#':
                re[i][j] = -1;
                break;
            case 'S':
                si = i;
                sj = j;
                re[i][j] = 1;
                break;
            case 'E':
                ei = i;
                ej = j;
                re[i][j] = 2;
                break;
            default:
                re[i][j] = 0;
                break;
            }
        }
    }
    vector<vector<int> > dp(n, vector<int>(m, minT));
    fun(si, sj, 0, 0, re, dp);
    cout << minT << endl;
    return 0;
}
