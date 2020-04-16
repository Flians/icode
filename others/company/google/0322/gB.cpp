#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxV;
int T, N, K, P;

void fun(int i, int num, int value, vector<vector<int>> values)
{
    if (i == N || num <= 0)
    {
        maxV = max(maxV, value);
        return;
    }
    int mx = min(num, K);
    for (int j = 0; j <= mx; ++j)
    {
        fun(i + 1, num - j, value + values[i][j], values);
    }
}

int main()
{
    int i, j, index = 1;
    cin >> T;
    while (T--)
    {
        cin >> N >> K >> P;
        int tp = 0;
        vector<vector<int>> values(N, vector<int>(K+1, 0));
        for (i = 0; i < N; ++i)
        {
            for (j = 1; j <= K; ++j)
            {
                cin >> tp;
                values[i][j] = tp + values[i][j - 1];
            }
        }
        maxV = 0;
        fun(0, P, 0, values);
        cout << "Case #" << (index++) << ": " << maxV << endl;
    }
    return 0;
}