#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <stack>
#include <limits.h>
using namespace std;

stack<int> s;

void dfs(int cur, vector<bool> &visit, vector<vector<int>> &matrix, int flag){
    visit[cur] = 1;
    for (int i = 1; i < visit.size(); ++i) {
        if (!visit[i] && matrix[cur][i] == flag)
            dfs(i, visit, matrix, flag);
    }
    s.push(cur);
}

int fun(vector<vector<int>> &matrix) {
    while (!s.empty())
        s.pop();
    vector<bool> visit(matrix.size()+1, 0);
    for (int i = 1; i < matrix.size(); ++i) {
        if (!visit[i])
            dfs(i, visit, matrix, 1);
    }

    int res = 0;
    vector<bool>(matrix.size()+1, 0).swap(visit);
    while (!s.empty())
    {
        int cur = s.top();
        s.pop();
        if (!visit[cur]) {
            ++res;
            dfs(cur, visit, matrix, -1);
        }
    }
    return res;
}

int main() {
    int m, n, x, y;
    cin >> n >> m;
    vector<vector<int>> matrix(n+1, vector<int>(n+1, 0));
    for (int i = 0; i < m; ++i) {
        cin >> x >> y;
        matrix[x][y] = 1;
        matrix[y][x] = -1;
    }
    cout << fun(matrix) << endl;
    return 0;
}