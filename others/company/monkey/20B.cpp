#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void search(int x, int y, int power, int cur, int &max_step, vector<vector<int> > &matrix)
{
    if (x > 0) {
        if (matrix[x][y] >= matrix[x - 1][y])
        {
            if (power == 0) {
                max_step = max(max_step, cur);
                return;
            }
            search(x - 1, y, power - 1, cur + 1, max_step, matrix);
        } else {
            search(x - 1, y, power, cur + 1, max_step, matrix);
        }
    }
    
    if (x < matrix.size() - 1) {
        if (matrix[x][y] >= matrix[x + 1][y])
        {
            if (power == 0) {
                max_step = max(max_step, cur);
                return;
            }
            search(x + 1, y, power - 1, cur + 1, max_step, matrix);
        } else {
            search(x + 1, y, power, cur + 1, max_step, matrix);
        }
    }
    
    if (y > 0) {
        if (matrix[x][y] >= matrix[x][y - 1])
        {
            if (power == 0) {
                max_step = max(max_step, cur);
                return;
            }
            search(x, y - 1, power - 1, cur + 1, max_step, matrix);
        } else {
            search(x, y - 1, power, cur + 1, max_step, matrix);
        }
    }
    
    if (y < matrix[0].size() - 1) {
        if (matrix[x][y] >= matrix[x][y + 1])
        {
            if (power == 0) {
                max_step = max(max_step, cur);
                return;
            }
            search(x, y + 1, power - 1, cur + 1, max_step, matrix);
        } else {
            search(x, y + 1, power, cur + 1, max_step, matrix);
        }
    }
}

int main(){
    int N,M,K;
    cin >> N >> M >> K;
    vector<vector<int> > matrix(N, vector<int>(M, 0));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> matrix[i][j];
        }
    }
    int max_step = 0;
    search(0, 0, K, 1, max_step, matrix);
    cout << max_step << endl;
    return 0;
}