#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int T, N;
long long D;

int main()
{
    int i, j, index = 1;
    cin >> T;
    while (T--)
    {
        cin >> N >> D;
        vector<long long> X(N,0);
        for (i = 0; i < N; ++i)
        {
            cin >> X[i];
        }
        for (i=N-1; i >= 0; --i) {
            D -= (D%X[i]);
        }

        cout << "Case #" << (index++) << ": " << D << endl;
    }
    return 0;
}