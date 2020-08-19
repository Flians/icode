#include "../base/icode.hpp"
class L967 : public icode
{
public:
	void run() {
        // Output: [181,292,707,818,929]
        print_res(numsSameConsecDiff(3, 7));
        // Output: [10,12,21,23,32,34,43,45,54,56,65,67,76,78,87,89,98]
        print_res(numsSameConsecDiff(2, 1));
        // Output: [0,1,2,3,4,5,6,7,8,9]
        print_res(numsSameConsecDiff(1, 0));
        // Output: [11,22,33,44,55,66,77,88,99]
        print_res(numsSameConsecDiff(2, 0));
    }
    void dfs(int index, int K, int cur, vector<int> &res) {
        if (index <= 1) {
            res.emplace_back(cur);
            return;
        }
        int last = cur%10 + K;
        if (last < 10) {
            dfs(index-1, K, cur*10 + last, res);
        }
        last = cur%10 - K;
        if (last >= 0 && K != 0)
        {
            dfs(index-1, K, cur*10 + last, res);
        }
    }
    vector<int> numsSameConsecDiff(int N, int K) {
        vector<int> res;
        if (N == 1) {
            res.push_back(0);
        }
        for (int i = 1; i <= 9 ; ++i) {
            dfs(N, K, i, res);
        }
        return res;
    }
};