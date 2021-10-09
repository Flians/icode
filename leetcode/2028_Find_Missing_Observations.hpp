#include "../base/icode.hpp"
class L2028 : public icode
{
public:
    void run()
    {
        // [2,3,2,2]
        print_res(missingRolls({1, 5, 6}, 3, 4));
    }

    vector<int> missingRolls(vector<int> &&rolls, int mean, int n)
    {
        int m = rolls.size();
        mean *= (m + n);
        for (int i : rolls)
            mean -= i;
        vector<int> res;
        if (mean < n || mean > n * 6)
            return res;
        res.resize(n, mean / n);
        mean %= n;
        for (int i = 0; i < mean; ++i)
            res[i] += 1;
        return res;
    }
};