#include "../base/icode.hpp"

class L771 : public icode
{
public:
    int numJewelsInStones(string J, string S)
    {
        int res = 0;
        map<char, int> record;
        for (auto c : J)
        {
            if (record.count(c) == 0)
                record[c] = 1;
        }
        for (auto c : S)
        {
            if (record.count(c))
                ++res;
        }
        return res;
    }

    void run()
    {
        cout << numJewelsInStones("aA", "aAAbbbb") << endl;
    }
};