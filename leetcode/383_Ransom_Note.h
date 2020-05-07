#include "../base/icode.h"
class L383 : public icode
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        map<char, int> record;
        int i = 0;
        for (; i < magazine.length(); ++i)
        {
            if (record.count(magazine[i]))
            {
                ++record[magazine[i]];
            }
            else
            {
                record[magazine[i]] = 1;
            }
        }
        for (i = 0; i < ransomNote.length(); ++i)
        {
            if (record.count(ransomNote[i]) && record[ransomNote[i]] > 0)
            {
                --record[ransomNote[i]];
            }
            else
            {
                return false;
            }
        }
        return true;
    }

    void run()
    {
        cout << canConstruct("aa", "ab") << endl;
    }
};