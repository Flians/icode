#include "../base/icode.hpp"
class L1551 : public icode
{
public:
    void run()
    {
        cout << minOperations(6) << " 9" << endl;
    }

    int minOperations(int n)
    {
        return n * n / 4;
    }
};