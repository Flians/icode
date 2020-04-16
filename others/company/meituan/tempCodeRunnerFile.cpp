#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    vector<vector<int>> sum(K, vector<int>(N, 0));
    int i = 0, j = 0, k = 0;
    while (i < N)
    {
        cin >> sum[0][i++];
    }
    for (i = 1; i < K; i++)
    {
        sum[i][0] = sum[i-1][0];
        for (j = 1; j < N; j++)
        {
            sum[i][j] += sum[i][j-1] + sum[i - 1][j];
            sum[i][j] %= 998244353;
        }
    }
    cout << sum[K-1][N-1] << endl;
    return 0;
}