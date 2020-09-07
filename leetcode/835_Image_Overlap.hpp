#include "../base/icode.hpp"
class L835 : public icode
{
public:
	void run() {
        vector<vector<int>> A = {{1,1,0},{0,1,0},{0,1,0}}, B = {{0,0,0},{0,1,1},{0,0,1}};
        cout << largestOverlap(A, B) << " 3" << endl;
    }

    int convolute(vector<vector<int>>& A, vector<vector<int>> &kernel, int xShift, int yShift) {
        int result = 0;
        for (size_t row = 0; row < A.size(); ++row)
            for (size_t col = 0; col < A.size(); ++col)
                result += A[row][col] * kernel[row + yShift][col + xShift];
        return result;
    }

    
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int N = A.size();
        vector<vector<int>> B_padded(3 * N - 2, vector<int>(3 * N - 2, 0));

        for (int row = 0; row < N; ++row)
            for (int col = 0; col < N; ++col)
                B_padded[row + N - 1][col + N - 1] = B[row][col];

        int maxOverlaps = 0;
        for (int xShift = 0; xShift < 2 * N - 1; ++xShift) {
            for (int yShift = 0; yShift < 2 * N - 1; ++yShift) {
                maxOverlaps = max(maxOverlaps,
                    convolute(A, B_padded, xShift, yShift));
            }
        }

        return maxOverlaps;
    }
};