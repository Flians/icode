#include "../base/icode.hpp"
class L9 : public icode
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
            return false;
        long pn = 0;
        int temp = x;
        while (temp)
        {
            pn = pn * 10 + temp % 10;
            temp /= 10;
        }
        if ((int)pn == x)
            return true;
        else
            return false;
    }

    void run()
    {
        cout << isPalindrome(121) << endl;
    }
};