#include <bits/stdc++.h>

#define for0(a, x) for (int(a) = 0; (a) < (x); (a)++)
#define for1(a, x) for (int(a) = 1; (a) <= (x); (a)++)
using namespace std;
const int maxn = 100;

int m, n, K;

int dp[maxn + 5][maxn + 5][maxn + 5];
int a[maxn + 5][maxn + 5];

void cal()
{

    dp[1][1][1] = a[1][1];
    for (int k = 2; k <= K; k++)
        dp[1][1][k] = -1;

    for (int j = 2; j <= n; j++)
    {
        dp[1][j][1] = dp[1][j - 1][1] + a[1][j];
        for (int k = 2; k <= K; k++)
            dp[1][j][k] = -1;
    }

    for (int i = 2; i <= m; i++)
    {
        for (int k = 1; k <= K; k++)
        {
            if (~dp[i - 1][1][k])
                dp[i][1][k] = a[i][1] + dp[i - 1][1][k];
            else
                dp[i][1][k] = -1;
        }

        for (int j = 2; j <= n; j++)
        {
            int ple = 1, pri = 1;

            int nex = 1;
            while (nex <= K)
            {
                int &x = dp[i - 1][j][ple];
                int &y = dp[i][j - 1][pri];

                if (x == -1 && y == -1)
                {
                    dp[i][j][nex++] = -1;
                    continue;
                }

                if (x >= y)
                {
                    dp[i][j][nex++] = x + a[i][j];
                    ple++;
                }
                else
                {
                    dp[i][j][nex++] = y + a[i][j];
                    pri++;
                }
            }
        }
    }
}
void normalSolve()
{
    while (cin >> m >> n >> K)
    {
        for1(i, m) for1(j, n) cin >> a[i][j];
        cal();

        for (int k = 1; k <= K; k++)
        {
            cout << dp[m][n][k] << (k == K ? '\n' : ' ');
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    normalSolve();

    return 0;
}