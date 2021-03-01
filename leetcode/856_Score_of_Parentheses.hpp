#include "../base/icode.hpp"
class L856 : public icode
{
public:
    void run()
    {
        cout << scoreOfParentheses("(()(()))") << " 6" << endl;
        cout << scoreOfParentheses("(())") << " 2" << endl;
    }

    int scoreOfParentheses_dc(string S)
    {
        return F(S, 0, S.size());
    }

    int F(string S, int i, int j)
    {
        //Score of balanced string S[i:j]
        int ans = 0, bal = 0;

        // Split string into primitives
        for (int k = i; k < j; ++k)
        {
            bal += S[k] == '(' ? 1 : -1;
            if (bal == 0)
            {
                if (k - i == 1)
                    ans++;
                else
                    ans += 2 * F(S, i + 1, k);
                i = k + 1;
            }
        }

        return ans;
    }

    int scoreOfParentheses_stack(string S)
    {
        stack<int> re;
        re.push(0); // The score of the current frame

        for (char c : S)
        {
            if (c == '(')
                re.push(0);
            else
            {
                int v = re.top();
                re.pop();
                int w = re.top();
                re.pop();
                re.push(w + max(2 * v, 1));
            }
        }

        return re.top();
    }

    int scoreOfParentheses(string S)
    {
        int ans = 0, bal = 0;
        for (int i = 0, len = S.size(); i < len; ++i)
        {
            if (S[i] == '(')
            {
                bal++;
            }
            else
            {
                bal--;
                if (S[i - 1] == '(')
                    ans += 1 << bal;
            }
        }
        return ans;
    }
};