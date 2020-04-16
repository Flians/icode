#include "../base/icode.h"

class L13 : public icode
{
public:
    int romanToInt(string s)
    {
        int i = 0, len = s.length(), res = 0;
        char last = '0';
        while (i < len)
        {
            switch (s[i])
            {
            case 'I':
                res += 1;
                break;
            case 'V':
                if (last == 'I')
                    res -= 2;
                res += 5;
                break;
            case 'X':
                if (last == 'I')
                    res -= 2;
                res += 10;
                break;
            case 'L':
                if (last == 'X')
                    res -= 20;
                res += 50;
                break;
            case 'C':
                if (last == 'X')
                    res -= 20;
                res += 100;
                break;
            case 'D':
                if (last == 'C')
                    res -= 200;
                res += 500;
                break;
            case 'M':
                if (last == 'C')
                    res -= 200;
                res += 1000;
                break;
            }
            last = s[i++];
        }
        return res;
    }

    void run()
    {
    }
};
