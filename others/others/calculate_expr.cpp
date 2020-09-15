#include <iostream>

using namespace std;

bool dfs(int n, int m, int cur, int index) {
    if (index == 4) {
        return cur == m;
    }
    if (dfs(n, m, cur + n, index + 1)) {
        return true;
    }
    if (dfs(n, m, cur - n, index + 1)) {
        return true;
    }
    if (index == 0) {
        cur = n;
        ++index;
    }
    if (dfs(n, m, cur * n, index + 1)) {
        return true;
    }
    if (dfs(n, m, cur / n, index + 1)) {
        return true;
    }
    return false;
}

int main() {
    int n ,m;
    cin >> n >> m;
    cout << dfs(n, m, 0, 0) << endl;
}