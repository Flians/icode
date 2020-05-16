#include "../base/icode.hpp"

class L201 : public icode
{
public:
    // The same part on the left
    int rangeBitwiseAnd(int m, int n)
    {
        while (m < n)
        {
            n &= n - 1;
        }
        return n;
    }

    void run()
    {
        cout << rangeBitwiseAnd(20000, 2147483647) << endl;
        cout << rangeBitwiseAnd(5, 7) << endl;
    }
};