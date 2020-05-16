#include "../base/icode.hpp"

class L6 : public icode
{
public:
    // nums:
    // 1 -> 1
    // 2 -> 2
    // 3 -> 4
    // 4 -> 6
    // n -> (n-1)*2
    string convert(string s, int numRows)
    {
        if (s.empty() || numRows == 1)
            return s;

        int interval = (numRows - 1) * 2;
        int i = 0, j = 0;
        string out = "";
        for (; i < numRows; i++)
        {
            for (j = 0; j + i < (int)s.length(); j += interval)
            {

                out += s[j + i];
                if (0 < i && i < numRows - 1 && (j + i + (numRows - i - 1) * 2) < (int)s.length())
                {
                    out += s[j + i + (numRows - i - 1) * 2];
                }
            }
        }
        return out;
    }

    void run()
    {
        cout << convert("PAYPALISHIRING", 3) << endl;
    }
};