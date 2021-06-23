#include "../base/icode.hpp"
class L870 : public icode
{
public:
    void run()
    {
        // [24,32,8,12]
        print_res(advantageCount({12, 24, 8, 32}, {13, 25, 32, 11}));
    }

    vector<int> advantageCount(vector<int> &&A, vector<int> &&B)
    {
        std::sort(A.begin(), A.end(), std::greater<int>());
        std::size_t n = A.size();
        vector<int> res(n, 0), order(n, 0);
        for (std::size_t i = 0; i < n; ++i)
        {
            order[i] = i;
        }
        std::sort(order.begin(), order.end(), [&B](int a, int b) {
            return B[a] > B[b];
        });
        int i = 0, j = n - 1;
        for (int k : order)
        {
            res[k] = A[i] > B[k] ? A[i++] : A[j--];
        }
        return res;
    }
};