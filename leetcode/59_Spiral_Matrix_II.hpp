#include "../base/icode.hpp"
class L59 : public icode
{
public:
	void run() {
        print_res(generateMatrix(1));
        print_res(generateMatrix(2));
        print_res(generateMatrix(3));
    }

    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int begin = 0, end = n-1, index = 1;
        while (begin <= end) {
            for (int i = begin; i < end; ++i) {
                res[begin][i] = index++;
                res[i][end] = res[begin][i] + end - begin;
                res[end][n-i-1] = res[i][end] + end - begin;
                res[n-i-1][begin] = res[end][n-i-1] + end - begin;
            }
            if (begin == end && n%2 == 1) {
                res[n-end-1][begin] = index;
            } else {
                index = res[n-end][begin] + 1;
            }
            ++begin;
            --end;
        }
        return res;
    }

    vector<vector<int>> generateMatrix2(int n) {
        int i=0, r=0, c=0, sum=n*n;
        vector<vector<int>> matrix(n, vector<int>());
        for (; i < n; i++) {
            matrix[i].resize(n);
        }
        int dre=0;
        for (i=1;i<=sum;i++)
        {
            switch(dre%4) {
                case 0:
                    matrix[r][c++]=i;
                    if (c==n || matrix[r][c]>0) {
                        dre++;
                        c--;
                        r++;
                    }
                    break;
                case 1:
                    matrix[r++][c]=i;
                    if (r==n || matrix[r][c]>0) {
                        dre++;
                        r--;
                        c--;
                    }
                    break;
                case 2:
                    matrix[r][c--]=i;
                    if (c==-1 || matrix[r][c]>0) {
                        dre++;
                        c++;
                        r--;
                    }
                    break;
                case 3:
                    matrix[r--][c]=i;
                    if (r==-1 || matrix[r][c]>0) {
                        dre++;
                        r++;
                        c++;
                    }
            }
        }
        return matrix;
    }
};