#include "../base/icode.h"

class L14 : public icode
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.empty())
            return "";
        string res = "";
        int i = 0, j = 0;
        int m = strs.size(), n = strs[0].length();
        for (; i < n; i++)
        {
            for (j = 1; j < m; j++)
            {
                if (strs[0][i] != strs[j][i])
                    break;
            }
            if (j != m)
                break;
            else
                res += strs[0][i];
        }
        return res;
    }

    void run()
    {
        vector<string> strs = {"dog", "racecar", "car"};
        cout << longestCommonPrefix(strs) << endl;
    }
};
