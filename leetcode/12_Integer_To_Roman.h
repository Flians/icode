#include "../base/icode.h"

class L12 : public icode
{
public:
    string intToRoman(int num)
    {
        string roman = "";
        int temp;
        while (num > 0)
        {
            if ((temp = num / 1000) != 0)
            {
                while (temp--)
                    roman += 'M';
                num %= 1000;
            }
            else if ((temp = num / 500) != 0)
            {
                if ((num % 500) >= 400)
                {
                    roman += "CM";
                    num %= 900;
                }
                else
                {
                    roman += 'D';
                    num %= 500;
                }
            }
            else if ((temp = num / 100) != 0)
            {
                if (temp == 4)
                {
                    roman += "CD";
                    num %= 400;
                }
                else
                {
                    while (temp--)
                        roman += 'C';
                    num %= 100;
                }
            }
            else if ((temp = num / 50) != 0)
            {
                if ((num % 50) >= 40)
                {
                    roman += "XC";
                    num %= 90;
                }
                else
                {
                    roman += 'L';
                    num %= 50;
                }
            }
            else if ((temp = num / 10) != 0)
            {
                if (temp == 4)
                {
                    roman += "XL";
                    num %= 40;
                }
                else
                {
                    while (temp--)
                        roman += 'X';
                    num %= 10;
                }
            }
            else if ((temp = num / 5) != 0)
            {
                if ((num % 5) >= 4)
                {
                    roman += "IX";
                    num %= 9;
                }
                else
                {
                    roman += 'V';
                    num %= 5;
                }
            }
            else
            {
                if (num == 4)
                {
                    roman += "IV";
                }
                else
                {
                    while (num--)
                        roman += 'I';
                }
                num = 0;
            }
        }
        return roman;
    }

    void run()
    {
    }
};