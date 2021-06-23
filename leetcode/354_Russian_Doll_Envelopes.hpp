#include "../base/icode.hpp"
class L354 : public icode
{
public:
    void run()
    {
        std::cout << maxEnvelopes({{5, 4}, {6, 4}, {6, 7}, {2, 3}}) << " 3" << std::endl;
        std::cout << maxEnvelopes({{1, 1}, {1, 1}, {1, 1}, {1, 1}}) << " 1" << std::endl;
    }

    int maxEnvelopes(vector<vector<int>> &&envelopes)
    {
        std::sort(envelopes.begin(), envelopes.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[0] == b[0] ? a[1] >= b[1] : a[0] < b[0];
        });
        std::vector<int> dp;
        for (auto &i : envelopes)
        {
            if (dp.empty() || i[1] > dp.back())
            {
                dp.push_back(i[1]);
            }
            else
            {
                dp[std::lower_bound(dp.begin(), dp.end(), i[1]) - dp.begin()] = i[1];
            }
        }
        return dp.size();
    }
};