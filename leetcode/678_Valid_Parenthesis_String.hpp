#include "../base/icode.hpp"
class L678 : public icode
{
public:
    // Time Limit Exceeded
    // "(((((*(()((((*((**(((()()*)()()()*((((**)())*)*)))))))(())(()))())((*()()(((()((()*(())*(()**)()(())"
    bool validString_BFS(string s, int index, int left)
    {
        if ((int)s.length() <= index)
        {
            return left == 0;
        }
        switch (s.at(index))
        {
        case '(':
            return validString_BFS(s, index + 1, left + 1);
            break;
        case ')':
            return left > 0 ? validString_BFS(s, index + 1, left - 1) : false;
            break;
        case '*':
            // empty
            if (validString_BFS(s, index + 1, left))
                return true;
            // (
            if (validString_BFS(s, index + 1, left + 1))
                return true;
            // )
            if (left > 0 && validString_BFS(s, index + 1, left - 1))
                return true;
            return false;
            break;
        default:
            return false;
        }
    }

    bool validString_O2n(string s)
    {
        int left = 0, right = 0, i = 0;
        for (; i < (int)s.length(); ++i)
        {
            if (s[i] == '(' || s[i] == '*')
                left++;
            else
                left--;
            if (left < 0)
                return false;
        }
        for (i = s.length() - 1; i >= 0; --i)
        {
            if (s[i] == ')' || s[i] == '*')
                right++;
            else
                right--;
            if (right < 0)
                return false;
        }
        return true;
    }

    /**
     * left表示在有左括号的情况下，将星号当作右括号时左括号的个数
     * leftExist表示将星号当作左括号时左括号的个数
     */
    bool validString_On(string s)
    {
        int left = 0, leftExist = 0, i = 0;
        for (; i < (int)s.length(); ++i)
        {
            if (s[i] == '(')
            {
                ++left;
                ++leftExist;
            }
            else if (s[i] == ')')
            {
                if (leftExist > 0)
                    --leftExist;
                --left;
            }
            else
            {
                if (leftExist > 0)
                    --leftExist;
                ++left;
            }
            if (left < 0)
                return false;
        }
        return leftExist == 0;
    }

    bool checkValidString(string s)
    {
        // return validString_BFS(s, 0, 0);
        // return validString_O2n(s);
        return validString_On(s);
    }

    void run()
    {
        cout << checkValidString("(((((*(()((((*((**(((()()*)()()()*((((**)())*)*)))))))(())(()))())((*()()(((()((()*(())*(()**)()(())") << endl;
    }
};