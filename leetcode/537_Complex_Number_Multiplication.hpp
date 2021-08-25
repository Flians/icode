#include "../base/icode.hpp"
class L537 : public icode
{
public:
    void run()
    {
        std::cout << complexNumberMultiply("1+-1i", "1+-1i") << " 0+-2i" << std::endl;
    }

    void extractParam(string &num, int &a, int &b)
    {
        a = 0, b = 0;
        int flag = 1, fg = 1, sg = 1;
        for (int i = 0, n = num.size(); i < n; ++i)
        {
            switch (num[i])
            {
            case '-':
            {
                if (flag == 1)
                {
                    fg *= -1;
                }
                else
                {
                    if (flag == 2)
                        flag = 0;
                    sg *= -1;
                }
                break;
            }
            case '+':
            {
                if (flag == 2)
                    flag = 0;
                break;
            }
            case 'i':
            {
                b *= sg;
                break;
            }
            default:
            {
                if (flag > 0)
                {
                    flag = 2;
                    a = a * 10 + num[i] - '0';
                }
                else
                {
                    b = b * 10 + num[i] - '0';
                }
            }
            }
        }
        a *= fg;
    }
    void intTostr(string &res, int a)
    {
        if (a < 0)
        {
            res += '-';
        }
        else if (a == 0)
        {
            res += '0';
            return;
        }
        string tmp;
        while (a != 0)
        {
            tmp += '0' + abs(a % 10);
            a /= 10;
        }
        reverse(tmp.begin(), tmp.end());
        res += tmp;
    }
    string complexNumberMultiply(string num1, string num2)
    {
        int a = 0, b = 0, c = 0, d = 0;
        extractParam(num1, a, b);
        extractParam(num2, c, d);
        int A_ = a * c - b * d;
        int B_ = a * d + b * c;
        string res;
        intTostr(res, A_);
        res += '+';
        intTostr(res, B_);
        res += 'i';
        return res;
    }
};