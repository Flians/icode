#include "../base/icode.hpp"
class L123 : public icode
{
public:
	void run() {
        vector<int> prices = {3,3,5,0,0,3,1,4};
        cout << maxProfit(prices) << " 6" << endl;
    }

    int maxProfit(vector<int>& prices) {
        int firstbuy = INT_MIN;
        int firstsell = 0;
        int secondbuy = INT_MIN;
        int secondsell = 0;

        for(int price : prices)
        {
            firstbuy = max(firstbuy , -price);
            firstsell = max(firstsell , price + firstbuy);
            secondbuy = max(secondbuy , firstsell - price);
            secondsell = max(secondsell , secondbuy + price);
        }
        return secondsell;
    }
};