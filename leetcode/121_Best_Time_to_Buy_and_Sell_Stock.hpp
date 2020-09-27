#include "../base/icode.hpp"
class L121 : public icode
{
public:
	void run() {}

    int maxProfit(vector<int>& prices) {
        if (prices.empty())
            return 0;
        int minp=prices[0], maxp = 0;
        for(size_t i = 0; i< prices.size(); i++)
        {
            minp = min(minp, prices[i]);
            maxp = max(maxp, prices[i]-minp);
        }
        return maxp;
    }
};