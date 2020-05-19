#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int T, N, K;

int main()
{
    int i, j, k, index = 1;
    cin >> T;
    while (T--)
    {
        int num = 0;
        cin >> N >> K;
        vector<int> A(N,0);
        vector<int> Ki(N,-1);
        j=0;
        for (i = 0; i < N; ++i)
        {
            cin >> A[i];
            if (A[i] == K) 
                Ki[j++] = i;
        }
        for (i = 0; i < j; i++) {
            int ti = Ki[i];
            for (k=K; k>0; --k) {
                if (A[ti++] != k)
                    break;
            }
            if (k == 0)
                ++num;
        }
        cout << "Case #" << (index++) << ": " << num << endl;
    }
    return 0;
}