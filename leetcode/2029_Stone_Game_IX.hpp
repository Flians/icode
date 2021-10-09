#include "../base/icode.hpp"
class L2029 : public icode
{
public:
    void run()
    {
        std::cout << stoneGameIX({1, 1, 7, 10, 8, 17, 10, 20, 2, 10}) << " true" << std::endl;
    }

    bool stoneGameIX(vector<int> &&stones)
    {
        int r[3] = {0};
        for (int i : stones)
        {
            ++r[i % 3];
        }
        if (r[0] % 2 == 0)
        {
            return (r[1] >= 1 && r[2] >= r[1]) || (r[2] >= 1 && r[1] >= r[2]);
        }
        else
        {
            return (r[2] >= 0 && r[1] >= r[2] + 3) || (r[1] >= 0 && r[2] >= r[1] + 3);
        }
        return false;
    }
};