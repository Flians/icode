#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int T, N;
long long D;

bool issqr(long long num)
{
    double c = sqrt(num);
    return c == int(c);
}

int main()
{
    int i, j, index = 1;
    cin >> T;
    while (T--)
    {
        cin >> N;
        vector<long long> A(N, 0);
        vector<long long> sum(N,0);
        cin >> A[0];
        sum[0] = A[0];
        D = issqr(A[0])?1:0;
        for (i = 1; i < N; ++i)
        {
            cin >> A[i];
            sum[i] = sum[i - 1] + A[i];
            if (issqr(sum[i]))
            {
                ++D;
            }
        }
        for (i = 0; i < N; ++i)
        {
            for (j = i + 1; j < N; ++j)
            {
                if (issqr(sum[j] - sum[i]))
                {
                    ++D;
                }
            }
        }
        cout << "Case #" << (index++) << ": " << D << endl;
    }
    return 0;
}