#include "../base/icode.hpp"
class L518 : public icode
{
public:
	void run() {
        vector<int> coins = {1, 2, 5};
        cout << change(5, coins) << " 4" << endl;
        
        coins = {3,5,7,8,9,10,11};
        cout << change(500, coins) << " 35502874" << endl;
    }

    int check_recusive(int index, vector<int>& coins, int amount) {
        if (index < 0) {
            return amount == 0;
        }
        if (amount == 0)
            return 1;
        int num = 0;
        while (index >= 0 && coins[index] > amount) {
            --index;
        }
        if (index < 0)
            return 0;
        while (coins[index] <= amount) {
            num += check_recusive(index - 1, coins, amount);
            amount -= coins[index];
            if (amount == 0)
                ++num;
            else if (coins[index] > amount)
                num += check_recusive(index - 1, coins, amount);
        }
        return num;
    }

    int check_dp(int amount, vector<int>& coins) {
        vector<vector<int> > dp(coins.size()+1, vector<int>(amount+1, 0));
        dp[0][0] = 1;
        for (size_t i = 1; i <= coins.size(); ++i) {
            dp[i][0] = 1;
            for (int j = 1; j <= amount; ++j) {
                dp[i][j] = dp[i - 1][j] + (j >= coins[i - 1] ? dp[i][j - coins[i - 1]] : 0);
            }
        }
        print_res(dp);
        return dp[coins.size()][amount];
    }
    
    int change(int amount, vector<int>& coins) {
        /*
        sort(coins.begin(), coins.end());
        return check_recusive(coins.size() - 1, coins, amount);
        */
        return check_dp(amount, coins);
    }
};