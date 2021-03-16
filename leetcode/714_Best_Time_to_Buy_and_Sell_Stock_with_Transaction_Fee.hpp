#include "../base/icode.hpp"
class L714 : public icode
{
public:
    void run()
    {
        cout << maxProfit({1, 3, 2, 8, 4, 9}, 2) << " 8" << endl;
    }

    int maxProfit(vector<int> &&prices, int fee)
    {
        int cash = 0, hold = -prices[0];
        for (std::size_t i = 0, n = prices.size(); i < n; ++i)
        {
            cash = max(cash, hold + prices[i] - fee);
            hold = max(hold, cash - prices[i]);
        }
        return cash;
    }
};