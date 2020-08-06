#include "../base/icode.hpp"
class L918 : public icode
{
public:
	void run() {
        vector<int> A = {1,-2,3,-2};
        cout << maxSubarraySumCircular(A) << " 3" << endl;
        A = {5,-3,5};
        cout << maxSubarraySumCircular(A) << " 10" << endl;
        A = {3,-1,2,-1};
        cout << maxSubarraySumCircular(A) << " 4" << endl;
        A = {3,-2,2,-3};
        cout << maxSubarraySumCircular(A) << " 3" << endl;
        A = {-2,-3,-1};
        cout << maxSubarraySumCircular(A) << " -1" << endl;
    }

    int maxSubarraySumCircular(vector<int>& A) {
        int max_cur = A[0], maxR = A[0];
        int min_cur = A[0], minR = A[0];
        int sum = A[0];
        for (size_t i = 1; i < A.size(); ++i) {
            sum += A[i];
            max_cur = max(A[i], A[i] + max_cur);
            maxR = max(maxR, max_cur);
            
            min_cur = min(A[i], A[i] + min_cur);
            minR = min(minR, min_cur);
        }
        return sum == minR ? maxR : max(maxR, sum - minR);
    }
};