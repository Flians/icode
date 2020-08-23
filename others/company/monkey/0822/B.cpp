#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;
int maxSubarraySumCircular(vector<int> &A)
{
    int max_cur = A[0], maxR = A[0];
    int min_cur = A[0], minR = A[0];
    int sum = A[0];
    for (size_t i = 1; i < A.size(); ++i)
    {
        sum += A[i];
        max_cur = max(A[i], A[i] + max_cur);
        maxR = max(maxR, max_cur);

        min_cur = min(A[i], A[i] + min_cur);
        minR = min(minR, min_cur);
    }
    return sum == minR ? maxR : max(maxR, sum - minR);
}

int main () {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> matrix(N, vector<int>(M, 0));
    for(int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> matrix[i][j];
        }
    }
    int res = INT_MIN;
    for(int i = 0; i < N; ++i) {
        for (int j = i; j < N; ++j) {
            int sum = 0;
            for (int k = 0; k < M; k++) {
                sum += (matrix[j][k] - matrix[i][k]);
                if (sum < 0)
                    sum = 0;
                if (sum > res)
                    res = sum;
            }
        }
    }
    cout << res << endl;
    return 0;
}