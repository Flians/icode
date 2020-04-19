#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int T, N;

int main()
{
    int i, j, index = 1;
    cin >> T;
    while (T--)
    {
        cin >> N;
        vector<int> H(N);
        for (i = 0; i < N; ++i)
        {
            cin >> H[i];
        }
        int numP=0;
        for (i = 1; i < N-1; ++i) {
            if (H[i]>H[i-1] && H[i]>H[i+1])
                ++numP;
        }
        cout << "Case #" << (index++) << ": " << numP << endl;
    }
    return 0;
}