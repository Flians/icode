#include "../base/icode.hpp"
class L2027 : public icode
{
public:
    void run()
    {
        std::cout << minimumMoves("XXOX") << " 2" << std::endl;
    }

    int minimumMoves(string s)
    {
        int res = 0, n = s.size();
        for (int i = 0; i < n; ++i)
        {
            if (s[i] != 'O')
            {
                i += 2;
                ++res;
            }
        }
        return res;
    }
};