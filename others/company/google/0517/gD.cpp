#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits.h>
using namespace std;

int T, N, Q;
int D;

int query(int beg, int end, vector<int> A)
{
    bool flag = true;
    int res = 0;
    for (int i = beg; i <= end; ++i)
    {
        if (flag)
        {
            res += A[i] * (i - beg + 1);
        }
        else
        {
            res -= A[i] * (i - beg + 1);
        }
        flag ^= true;
    }
    return res;
}

void update(int index, int value, vector<vector<int>> &Tab) {
    for (int i = 0; i <= index; ++i)
    {
        for (int j = index; j<N; ++j) {
            if (Tab[i][j] != INT_MAX)
            Tab[i][j] += value*(j-i+1)*pow(-1,j-i);
        }
    }
}

int main()
{
    int i, index = 1;
    cin >> T;
    while (T--)
    {
        cin >> N >> Q;
        vector<int> A(N, 0);
        vector<vector<int>> Tab(N, vector<int>(N, INT_MAX));
        for (i = 0; i < N; ++i)
        {
            cin >> A[i];
        }
        string Op;
        int beg, end;
        D = 0;
        while (Q--)
        {
            cin >> Op;
            cin >> beg >> end;
            if (Op == "Q")
            {
                if (Tab[beg - 1][end - 1] == INT_MAX)
                {
                    Tab[beg - 1][end - 1] = query(beg - 1, end - 1, A);
                }
                D += Tab[beg - 1][end - 1];
            }
            else
            {
                A[beg - 1] = end;
                update(beg-1, end, Tab);
            }
        }
        cout << "Case #" << (index++) << ": " << D << endl;
    }
    return 0;
}