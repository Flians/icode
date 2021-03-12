#include "../base/icode.hpp"
class L322 : public icode
{
public:
    void run()
    {
        std::cout << coinChange({186, 419, 83, 408}, 6249) << " 20" << std::endl;
    }

    int coinChange(vector<int> &&coins, int amount)
    {
        int num = coins.size();
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i)
        {
            for (int j = 0; j < num; ++j)
            {
                if (coins[j] <= i && dp[i - coins[j]] + 1 < dp[i])
                {
                    dp[i] = dp[i - coins[j]] + 1;
                }
            }
        }
        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }
};