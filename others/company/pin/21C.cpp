#include <iostream>
#include <vector>
#include <cmath>
#include <limits.h>
#include <algorithm>
using namespace std;
bool cmp(vector<int> &a, vector<int> &b) {
    if (a[1] == b[1]) {
        return a[0] < b[0];
    } else {
        return a[1] < b[1];
    }
}

int func(vector<vector<int> > &lunch, vector<vector<int> > &dinner, int T, int &minP) {
    for (int i = 0; i<lunch.size(); ++i) {
        for (int j = dinner.size() - 1; j >= 0; --j) {
            if (lunch[i][1] + dinner[j][1] < T) break;
            minP = min(minP, lunch[i][0] + dinner[j][0]);
        }
    }
    return minP;
}

int main() {
    int N, M, T;
    cin >> N >> M >> T;
    int maxLT = 0, maxDT = 0;
    int minLP = INT_MAX, minDP = INT_MAX;
    vector<vector<int> > lunch(N, vector<int>(2, 0));
    vector<vector<int> > dinner(M, vector<int>(2, 0));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 2; ++j) {
            cin >> lunch[i][j];
        }
        maxLT = max(maxLT, lunch[i][1]);
        if (lunch[i][1] >= T)
            minLP = min(minLP, lunch[i][0]);
    }
    sort(lunch.begin(), lunch.end(), cmp);
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < 2; ++j) {
            cin >> dinner[i][j];
        }
        maxDT = max(maxDT, dinner[i][1]);
        if (dinner[i][1] >= T)
            minDP = min(minDP, dinner[i][0]);
    }
    sort(dinner.begin(), dinner.end(), cmp);
    if (T == 0) {
        cout << 0 << endl;
    } else if (maxLT + maxDT < T) {
        cout << -1 << endl;
    } else {
        int minP = min(minLP, minDP);
        cout << func(lunch, dinner, T, minP) << endl;
    }
    return 0;
}