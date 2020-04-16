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
        for (; i < strs[0].length(); i++)
        {
            for (j = 1; j < strs.size(); j++)
            {
                if (strs[0][i] != strs[j][i])
                    break;
            }
            if (j != strs.size())
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
