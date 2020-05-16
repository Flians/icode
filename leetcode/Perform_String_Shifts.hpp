#include "../base/icode.hpp"

class Solution_ : public icode
{
public:
    string stringShift(string s, vector<vector<int> > &shift)
    {
        // left <0, right >0
        int sf = 0;
        for (auto item : shift)
        {
            if (item[0] == 0)
            {
                sf -= item[1];
            }
            else
            {
                sf += item[1];
            }
        }
        if (sf > 0)
        {
            sf %= s.length();
            s = s.substr(s.length() - sf, sf) + s.substr(0, s.length() - sf);
        }
        else if (sf < 0)
        {
            sf = (0 - sf) % s.length();
            s = s.substr(sf) + s.substr(0, sf);
        }
        return s;
    }

    void run()
    {
        string s = "wpdhhcj";
        int a[7][2] = { {0, 7},
                        {1, 7},
                        {1, 0},
                        {1, 3},
                        {0, 3},
                        {0, 6},
                        {1, 2} };
        vector<vector<int> > shift;
        for (auto item: a) {
            shift.push_back(vector<int>(item, item+2));
        }
        cout << stringShift(s, shift) << endl;
    }
};