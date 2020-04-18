#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxV;
int T, N, K, P;

void fun_DFS(int i, int num, int value, vector<vector<int>> values)
{
    if (i == N || num <= 0)
    {
        maxV = max(maxV, value);
        return;
    }
    int mx = min(num, K);
    for (int j = 0; j <= mx; ++j)
    {
        fun_DFS(i + 1, num - j, value + values[i][j], values);
    }
}

int fun_DP(vector<vector<int>> values)
{
    vector<vector<int>> dp(N + 1, vector<int>(P + 1, 0));
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 0; j <= P; ++j)
        {
            int temp = min(j, K);
            for (int k = 0; k <= temp; ++k)
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - k] + values[i-1][k]);
            }
        }
    }
    return dp[N][P];
}

int main()
{
    int i, j, index = 1;
    cin >> T;
    while (T--)
    {
        cin >> N >> K >> P;
        int tp = 0;
        vector<vector<int>> values(N, vector<int>(K + 1, 0));
        for (i = 0; i < N; ++i)
        {
            for (j = 1; j <= K; ++j)
            {
                cin >> tp;
                values[i][j] = tp + values[i][j - 1];
            }
        }
        maxV = 0;
        // fun_DFS(0, P, 0, values);
        // cout << "Case #" << (index++) << ": " << maxV << endl;
        cout << "Case #" << (index++) << ": " << fun_DP(values) << endl;
    }
    return 0;
}