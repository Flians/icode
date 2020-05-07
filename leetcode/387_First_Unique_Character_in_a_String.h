#include "../base/icode.h"

class L387 : public icode
{
public:
    int firstUniqChar(string s)
    {
        map<char, int> record;
        int i = 0;
        for (; i < (int)s.length(); ++i)
        {
            record[s[i]] = record.count(s[i]) + 1;
        }
        for (i = 0; i < (int)s.length(); ++i)
        {
            if (record[s[i]] == 1)
                return i;
        }
        return -1;
    }

    void run()
    {
        cout << firstUniqChar("leetcode") << endl;
    }
};