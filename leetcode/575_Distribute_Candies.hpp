#include "../base/icode.hpp"
class L575 : public icode
{
public:
    void run()
    {
        cout << distributeCandies({1, 1, 2, 2, 3, 3}) << " 3" << endl;
    }

    int distributeCandies(vector<int> &&candyType)
    {
        set<int> candy;
        for (int i : candyType)
        {
            candy.insert(i);
        }
        int lim = candy.size(), n = candyType.size() / 2;
        return lim > n ? n : lim;
    }
};