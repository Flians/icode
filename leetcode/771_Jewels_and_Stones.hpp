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

    int numJewelsInStones_2(string J, string S) {
        vector<vector<int> > stones(2, vector<int>(26, 0));
        for (size_t i = 0; i < S.length(); ++i) {
            if (S[i] >= 'A' && S[i] <= 'Z') {
                ++stones[1][S[i]-'A'];
            } else {
                ++stones[0][S[i]-'a'];
            }
        }
        int res = 0;
        for (size_t i = 0; i < J.length(); ++i) {
            if (J[i] >= 'A' && J[i] <= 'Z') {
                res += stones[1][J[i]-'A'];
            } else {
                res += stones[0][J[i]-'a'];
            }
        }
        return res;
    }

    void run()
    {
        cout << numJewelsInStones("aA", "aAAbbbb") << endl;
    }
};