#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

//二分答案

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
        vector<int> sessions(N, 0);
        cin >> sessions[0];
        for (i = 1; i < N; ++i)
        {
            cin >> sessions[i];
            sessions[i - 1] = sessions[i] - sessions[i - 1];
        }
        sessions.pop_back();
        sort(sessions.begin(), sessions.end(), greater<int>());
        maxV = 1;
        while (K--)
        {
            while (!sessions.empty() && sessions.back() == 1)
                sessions.pop_back();
            if (sessions.empty())
                break;
            int s0 = sessions[0] / 2;
            int s1 = s0;
            if (sessions[0] % 2 == 1)
            {
                ++s1;
            }
            sessions[0] = s1;
            sessions.push_back(s0);
            sort(sessions.begin(), sessions.end(), greater<int>());
        }
        if (!sessions.empty()) {
            maxV = sessions[0];
        }
        cout << "Case #" << (index++) << ": " << maxV << endl;
    }
    return 0;
}