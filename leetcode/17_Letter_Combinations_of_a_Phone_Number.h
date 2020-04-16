#include "../base/icode.h"
class L17 : public icode
{
public:
    void lc(int index, string digits, string item, vector<string> &result)
    {
        if (index < digits.length())
        {
            int i = 0;
            int num = digits[index] - '0';
            switch (num)
            {
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
                for (i = 0; i <= 2; i++)
                {
                    lc(index + 1, digits, item + (char)((num - 2) * 3 + i + 'a'), result);
                }
                break;
            case 7:
                for (i = 0; i <= 3; i++)
                {
                    lc(index + 1, digits, item + (char)((num - 2) * 3 + i + 'a'), result);
                }
                break;
            case 8:
                for (i = 0; i <= 2; i++)
                {
                    lc(index + 1, digits, item + (char)((num - 2) * 3 + 1 + i + 'a'), result);
                }
                break;
            case 9:
                for (i = 0; i <= 3; i++)
                {
                    lc(index + 1, digits, item + (char)((num - 2) * 3 + 1 + i + 'a'), result);
                }
                break;
            }
        }
        else
        {
            result.push_back(item);
        }
    }

    vector<string> letterCombinations(string digits)
    {
        vector<string> result;
        if (digits.length() == 0)
        {
            return result;
        }
        lc(0, digits, "", result);
        return result;
    }

    void run()
    {
    }
};