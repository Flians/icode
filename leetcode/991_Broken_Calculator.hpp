#include "../base/icode.hpp"
class L991 : public icode
{
public:
    void run()
    {
        cout << brokenCalc(2, 3) << " 2" << endl;
    }

    int brokenCalc(int X, int Y)
    {
        int res = 0;
        while (X < Y)
        {
            ++res;
            if (Y % 2)
                ++Y;
            else
                Y /= 2;
        }
        return res + X - Y;
    }
};