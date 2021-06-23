#include "../base/icode.hpp"
class L1332 : public icode
{
public:
    void run()
    {
        cout << removePalindromeSub("baabb") << " 2" << endl;
    }

    int removePalindromeSub(string s)
    {
        if (s.empty())
            return 0;
        std::string old = s;
        std::reverse(s.begin(), s.end());
        return old == s ? 1 : 2;
    }
};