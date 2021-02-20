#include "../base/icode.hpp"
class L1249 : public icode
{
public:
    void run()
    {
        cout << minRemoveToMakeValid("lee(t(c)o)de)") << " lee(t(c)o)de" << endl;
        cout << minRemoveToMakeValid("))((") << "  " << endl;
    }

    string minRemoveToMakeValid(string s)
    {
        size_t len = s.size(), left = 0;
        for (size_t i = 0; i < len; ++i)
        {
            if (s[i] == '(')
            {
                ++left;
            }
            else if (s[i] == ')')
            {
                if (left == 0)
                {
                    s.erase(s.begin() + i);
                    --i, --len;
                }
                else
                {
                    --left;
                }
            }
        }
        if (left == 0 || len == 0)
            return s;
        left = 0;
        for (int i = len - 1; i >= 0; --i)
        {
            if (s[i] == ')')
            {
                ++left;
            }
            else if (s[i] == '(')
            {
                if (left == 0)
                {
                    s.erase(s.begin() + i);
                }
                else
                {
                    --left;
                }
            }
        }
        return s;
    }
};