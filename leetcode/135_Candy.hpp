#include "../base/icode.hpp"
class L135 : public icode
{
public:
    void run()
    {
        cout << candy({1, 0, 2}) << " 5" << endl;
    }

    int candy(vector<int> &&ratings)
    {
        size_t i = 0, num = ratings.size();
        vector<int> candies(num, 1);
        for (; i < num - 1; ++i)
        {
            if (ratings[i + 1] > ratings[i])
                candies[i + 1] = candies[i] + 1;
        }
        int sum = 0;
        for (i = num - 1; i > 0; --i)
        {
            sum += candies[i];
            if (ratings[i] < ratings[i - 1])
                candies[i - 1] = max(candies[i] + 1, candies[i - 1]);
        }
        return sum + candies[0];
    }
};