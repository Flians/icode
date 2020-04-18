#include <iostream>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

int T, N, K;

int fun_(vector<int> sessions)
{
    sort(sessions.begin(), sessions.end(), greater<int>());
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
    int maxV = 1;
    if (!sessions.empty())
    {
        maxV = sessions[0];
    }
    return maxV;
}

int fun_pq(vector<int> sessions)
{
    priority_queue<int, vector<int>, less<int>> pq;
    for (auto it:sessions)
    {
        if (it > 1)
            pq.push(it);
    }

    while (K--)
    {
        if (pq.empty())
            break;
        int s0 = pq.top() / 2;
        int s1 = s0;
        if (pq.top() % 2 == 1)
        {
            ++s1;
        }
        pq.pop();
        if (s0 > 1)
            pq.push(s0);
        if (s1 > 1)
            pq.push(s1);
    }
    int maxV = 1;
    if (!pq.empty())
    {
        maxV = pq.top();
    }
    return maxV;
}

int check(int mid, vector<int> sessions)
{
    int num = 0;
    for (auto it:sessions)
    {
        if (it > mid)
            num += ceil(double(it) / mid)-1;
    }
    return num;
}

// Dichotomous answer
int fun_da(vector<int> sessions, int maxS)
{
    int left = 1, right = maxS;
    while (left <= right)
    {
        int mid = (right + left) >> 1, num = check(mid, sessions);
        if (num > K)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return left;
}

int main()
{
    int index = 1;
    cin >> T;
    while (T--)
    {
        cin >> N >> K;
        int bef = 0, next = 0, maxS=0;
        vector<int> sessions;
        cin >> bef;
        for (int i = 1; i < N; ++i)
        {
            cin >> next;
            bef = next - bef;
            maxS = max(maxS, bef);
            if (bef > 1)
                sessions.push_back(bef);
            bef = next;
        }
        cout << "Case #" << (index++) << ": " << fun_da(sessions, maxS) << endl;
    }
    return 0;
}