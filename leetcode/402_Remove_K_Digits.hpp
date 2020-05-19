#include "../base/icode.hpp"
class L402 : public icode
{
public:
    string removeKdigits(string num, int k)
    {
        if (k == 0 || num.empty())
            return num;
        string res;
        unsigned i = 0;
        while (num.size() > i)
        {
            if (res.empty() || res.back() <= num.at(i) || k <= 0)
            {
                res.push_back(num.at(i++));
            }
            else
            {
                res.pop_back();
                --k;
            }
        }
        i = 0;
        while (res.size() > i && res.at(i) == '0')
            ++i;
        while (res.size() > 0 && k--)
            res.pop_back();
        return (i == res.size() || res.empty()) ? "0" : res.substr(i, res.length() - i);
    }

    void run()
    {
        // 11
        cout << removeKdigits("112", 1) << endl;
        // 1
        cout << removeKdigits("21", 1) << endl;
        // 0
        cout << removeKdigits("9", 1) << endl;
        // 0
        cout << removeKdigits("10", 2) << endl;
        // 1219
        cout << removeKdigits("1432219", 3) << endl;
        // 200
        cout << removeKdigits("10200", 1) << endl;
        // 0
        cout << removeKdigits("10", 1) << endl;
    }
};