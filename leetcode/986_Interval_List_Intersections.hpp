#include "../base/icode.hpp"
class L986 : public icode
{
public:
	void run() {
        vector<vector<int>> A = {{0,2},{5,10},{13,23},{24,25}}, B = {{1,5},{8,12},{15,24},{25,26}};
        // [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
        print_res(intervalIntersection(A, B));
    }

    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> res;
        size_t i = 0, j = 0;
        for (; i < A.size(); ++i) {
            for (; j < B.size(); ++j) {
                if (B[j][0] > A[i][1]) break;
                if (B[j][1] < A[i][0]) continue;
                vector<int> item = {max(A[i][0], B[j][0]), min(A[i][1], B[j][1])};
                res.emplace_back(item);
                if (A[i][1] < B[j][1]) {
                    B[j][0] = A[i][1] + 1;
                    break;
                } else if (A[i][1] == B[j][1]) {
                    break;
                } else {
                    A[i][0] = B[j][1] + 1;
                }
            }
        }
        return res;
    }
};