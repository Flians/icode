#include "../base/icode.hpp"
class L838 : public icode
{
public:
    void run()
    {
        std::cout << pushDominoes(".L.R...LR..L..") << " LL.RR.LLRRLL.." << std::endl;
    }

    string pushDominoes(string dominoes)
    {
        int n = dominoes.size(), f = 0;
        vector<int> force(n, 0);
        string res(n, '.');
        for (int i = n - 1; i >= 0; --i)
        {
            switch (dominoes[i])
            {
            case 'R':
                f = 0;
                break;
            case 'L':
                f = n;
                break;
            default:
                f = max(f - 1, 0);
            }
            force[i] -= f;
        }
        f = 0;
        for (int i = 0; i < n; ++i)
        {
            switch (dominoes[i])
            {
            case 'R':
                f = n;
                break;
            case 'L':
                f = 0;
                break;
            default:
                f = max(f - 1, 0);
            }
            force[i] += f;
            res[i] = force[i] > 0 ? 'R' : (force[i] < 0 ? 'L' : '.');
        }
        return res;
    }
};