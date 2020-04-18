#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
// greedy
int maxV;
int T, N, K;

int main()
{
    int i, j, index = 1;
    cin >> T;
    while (T--)
    {
        cin >> N >> K;
        int tp = 0;
        vector<string> sessions(N);
        for (i = 1; i < N; ++i)
        {
            cin >> sessions[i];
        }
        sort(sessions.begin(), sessions.end());
        maxV = 0, i = 0;
        while (i < N) {
            j=1;
            int k=0;
            bool flag = 0; 
            while (k < sessions[i].length() && j<K) {
                
            }
        }

        cout << "Case #" << (index++) << ": " << maxV << endl;
    }
    return 0;
}