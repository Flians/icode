#include "../base/icode.hpp"
class L905 : public icode
{
public:
	void run() {
        vector<int> A = {3,1,2,4};
        print_res(sortArrayByParity(A));
        A = {1,0,3};
        print_res(sortArrayByParity(A));
    }

    vector<int> sortArrayByParity(vector<int>& A) {
        int l=0, r=A.size()-1, m=0;
        while (m < r) {
            if (A[m]%2 == 0) {
                swap(A[l++], A[m++]);
            } else{
                swap(A[r--], A[m]);
            }
        }
        return A;
    }
};