#include "../base/icode.hpp"
class L848 : public icode
{
public:
    void run()
    {
        cout << shiftingLetters("mkgfzkkuxownxvfvxasy",
                                {505870226, 437526072, 266740649, 224336793, 532917782, 311122363, 567754492, 595798950, 81520022, 684110326, 137742843, 275267355, 856903962, 148291585, 919054234, 467541837, 622939912, 116899933, 983296461, 536563513})
             << " wqqwlcjnkphhsyvrkdod" << endl;
    }

    string shiftingLetters(string s, vector<int> &&shifts)
    {
        int n = s.size();
        for (int i = n - 1; i >= 0; --i)
        {
            shifts[i] += i < n - 1 ? shifts[i + 1] : 0;
            shifts[i] %= 26;
            s[i] = (s[i] - 'a' + shifts[i]) % 26 + 'a';
        }
        return s;
    }
};