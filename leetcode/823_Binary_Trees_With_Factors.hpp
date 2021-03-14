#include "../base/icode.hpp"
class L823 : public icode
{
public:
    void run()
    {
        cout << numFactoredBinaryTrees({18, 3, 6, 2}) << " 12" << endl;
    }

    int numFactoredBinaryTrees(vector<int> &&arr)
    {
        int mod = 1e9 + 7;
        std::sort(arr.begin(), arr.end());
        std::size_t n = arr.size();
        std::vector<long> dp(n, 1);
        std::map<int, int> index;
        for (std::size_t i = 0; i < n; ++i)
            index[arr[i]] = i;
        auto end = index.end();
        long res = 0;
        for (std::size_t i = 0; i < n; ++i)
        {
            for (std::size_t j = 0; j < i; ++j)
            {
                if (arr[i] % arr[j] == 0)
                {
                    int right = arr[i] / arr[j];
                    if (index.find(right) != end)
                    {
                        dp[i] = (dp[i] + dp[j] * dp[index[right]]) % mod;
                    }
                }
            }
            res = (res + dp[i]) % mod;
        }
        return res;
    }
};