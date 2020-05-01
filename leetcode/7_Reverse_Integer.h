#include "../base/icode.h"
class L7 : public icode
{
public:
    int reverse(int x)
    {
        int rx = 0;
        while (x != 0)
        {
            if (rx > 214748364 || rx < -214748364 ||
                (rx == 214748364 && (x % 10) >= 8) || (rx == -214748364 && (x % 10) == -9))
                return 0;
            // cout << x%10 << endl;
            rx = rx * 10 + (x % 10);
            x /= 10;
        }
        return rx;
    }

    void run()
    {
        cout << reverse(-123) << endl;
    }
};