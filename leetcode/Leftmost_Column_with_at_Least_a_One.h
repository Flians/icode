#include "../base/icode.h"

class Solution : public icode {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> xy = binaryMatrix.dimensions();
        int r=0, c=xy[1]-1;
        while (r<xy[0] && c>=0) {
            if (binaryMatrix.get(r,c)) {
                --c;
            } else {
                ++r;
            }
        }
        if (c==xy[1]-1)
            return -1;
        else
            return c+1;
    }

    void run() {
        vector<vector<int> > nums = {{0,0,0,1},{0,0,1,1},{0,1,1,1}};
    }
};