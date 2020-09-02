#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
void print_rich(int n) {
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    for (int i = 0; i < floor(n/2.0); ++i) {
        for (int j = 0; j < i; ++j) {
            matrix[i][j] = 3;
        }
        for (int j = i+1; j < floor(n/2.0); ++j) {
            matrix[i][j] = 2;
        }
        for (int j = ceil(n/2.0); j < n-i-1; ++j) {
            matrix[i][j] = 1;
        }
        for (int j = n-i; j < n; ++j) {
            matrix[i][j] = 8;
        }
    }
    for (int i = ceil(n/2.0); i < n; ++i) {
        for (int j = 0; j < n-i-1; ++j) {
            matrix[i][j] = 4;
        }
        for (int j = n-i; j < floor(n/2.0); ++j) {
            matrix[i][j] = 5;
        }
        for (int j = ceil(n/2.0); j < i; ++j) {
            matrix[i][j] = 6;
        }
        for (int j = i+1; j < n; ++j) {
            matrix[i][j] = 7;
        }
    }
    for (auto &line : matrix) {
        for (int i = 0; i < n-1; ++i) {
            cout << line[i] << " ";
        }
        cout << line.back() << endl;
    }
}
int main() {
    int n;
    cin >> n;
    print_rich(n);
}