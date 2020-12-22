#include "../base/icode.hpp"
class L910 : public icode
{
public:
	void run() {
        cout << smallestRangeII({1,3,6}, 3) << " 3" << endl;
    }

    int smallestRangeII(vector<int>&& A, int K) {
        int n = A.size();
        sort(A.begin(), A.end());
        int gap = A[n-1] - A[0];
        for (int i = 0; i < n-1; ++i) {
            gap = min(gap, max(A[n-1] - K, A[i] + K) - min(A[0] + K, A[i+1] - K));
        }
        return gap;
    }
};