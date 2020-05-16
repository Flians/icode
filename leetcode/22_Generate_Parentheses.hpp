#include "../base/icode.hpp"

class L22 : public icode
{
public:
    void gp(int lp, int rp, stack<char> up, string np, vector<string> &all)
    {
        if (lp == 0)
        {
            while (rp--)
            {
                up.pop();
                np += ")";
            }
            all.push_back(np);
        }
        else
        {
            if (up.empty())
            {
                up.push('(');
                np += "(";
                gp(lp - 1, rp, up, np, all);
            }
            else
            {
                up.push('(');
                np += "(";
                gp(lp - 1, rp, up, np, all);

                up.pop();
                up.pop();
                np[np.length() - 1] = ')';
                gp(lp, rp - 1, up, np, all);
            }
        }
    }

    vector<string> generateParenthesis(int n)
    {
        stack<char> up;
        vector<string> all;
        up.push('(');
        if (n > 0)
            gp(n - 1, n, up, "(", all);
        return all;
    }

    void run()
    {
        icode::print_res(generateParenthesis(3));
    }
};