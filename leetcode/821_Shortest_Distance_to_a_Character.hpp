#include "../base/icode.hpp"
class L821 : public icode
{
public:
    void run()
    {
        // [3,2,1,0,1,0,0,1,2,2,1,0]
        print_res(shortestToChar("loveleetcode", 'e'));
    }
    vector<int> shortestToChar(string s, char c)
    {
        int len = s.size(), pre = -len;
        vector<int> res(len, 0);
        for (int i = 0; i < len; ++i)
        {
            if (s[i] == c)
            {
                pre = i;
            }
            res[i] = i - pre;
        }
        pre = INT_MAX;
        for (int i = len - 1; i >= 0; --i)
        {
            if (s[i] == c)
            {
                pre = i;
            }
            res[i] = min(res[i], pre - i);
        }
        return res;
    }
};