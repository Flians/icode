#include "../base/icode.hpp"
class L415 : public icode
{
public:
    void run()
    {
        std::cout << addStrings("1", "9") << " 10" << std::endl;
    }

    string addStrings(string num1, string num2)
    {
        string res;
        int n1 = num1.size(), n2 = num2.size(), carry = 0;
        for (int i = n1 - 1, j = n2 - 1; i >= 0 || j >= 0; --i, --j)
        {
            int tmp = carry;
            if (i >= 0)
            {
                tmp += num1[i] - '0';
            }
            if (j >= 0)
            {
                tmp += num2[j] - '0';
            }
            res = (char)(tmp % 10 + '0') + res;
            carry = tmp / 10;
        }
        if (carry > 0)
        {
            res = (char)(carry + '0') + res;
        }
        return res;
    }
};