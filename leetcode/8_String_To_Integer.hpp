#include "../base/icode.hpp"

class L8 : public icode
{
public:
    int myAtoi(string str)
    {
        string num = "";
        int i = 0, len = str.length(), pos = 1;
        bool flag = false;
        for (; i < len; i++)
        {
            if (flag)
            {
                if (str[i] >= '0' && str[i] <= '9')
                    num += str[i];
                else
                    break;
            }
            else
            {
                if (str[i] != ' ')
                {
                    flag = true;
                    if (str[i] >= '0' && str[i] <= '9')
                        num += str[i];
                    else if (str[i] == '+')
                    {
                        pos = 1;
                    }
                    else if (str[i] == '-')
                    {
                        pos = -1;
                    }
                    else
                        return 0;
                }
            }
        }
        int res = 0;
        len = num.length();
        if (len == 0)
            return 0;
        i = 0;
        while (i < len)
        {
            if (res > 214748364 || (res == 214748364 && num[i] >= '8'))
            {
                return pos == 1 ? INT_MAX : INT_MIN;
            }
            res = res * 10 + (num[i++] - '0');
        }
        return res * pos;
    }

    void run()
    {
        cout << myAtoi("-91283472332") << endl;
    }
};