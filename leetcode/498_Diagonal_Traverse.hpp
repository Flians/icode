#include "../base/icode.hpp"
class L498 : public icode
{
public:
	void run() {
        print_res(findDiagonalOrder({{ 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 }}));
    }

    vector<int> findDiagonalOrder(vector<vector<int>>&& matrix) {
        vector<int> res;
        if (matrix.empty()) return res;
        int n = matrix.size(), m = matrix[0].size(), x = 0, y = 0;
        res.reserve(n*m);
        bool flag = true;
        while ((int) res.size() != n*m) {
            if (flag) {
                while (x >=0 && y < m) {
                    res.push_back(matrix[x--][y++]);
                }
                if (y == m) {
                    x += 2;
                    y -= 1;
                } else {
                    ++x;
                }
                flag = 0;
            } else {
                while (x < n && y >= 0) {
                    res.push_back(matrix[x++][y--]);
                }
                if (x == n) {
                    y += 2;
                    x -= 1;
                } else {
                    ++y;
                }
                flag = 1;
            }
        }
        return res;
    }
};