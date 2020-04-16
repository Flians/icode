#include "../base/icode.h"

class L3: public icode
{
public:
    int lengthOfLongestSubstring(string s)
    {
        if (s.length() == 0)
            return 0;
        int begin = 0, end = 0, length = 1, temp = 0, max_temp = 1;
        for (; begin < s.length() - 1; begin++)
        {
            for (end = begin + 1; end < s.length(); end++)
            {
                for (temp = end - 1; temp >= begin; temp--)
                {
                    if (s[end] == s[temp])
                        break;
                }
                if (temp != begin - 1)
                    break;
            }
            length = max(length, end - begin);
        }
        return length;
    }

    void run() {
        cout << lengthOfLongestSubstring("aux") << endl;
    }
};