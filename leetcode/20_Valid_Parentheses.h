#include "../base/icode.h"
class L20 : public icode
{
public:
    bool isValid(string s)
    {
        stack<char> brackets;
        int i = 0, len = s.length();
        map<char, char> symbols = {
            {'}', '{'},
            {']', '['},
            {')', '('}};
        while (i < len)
        {
            switch (s[i])
            {
            case '{':
            case '[':
            case '(':
                brackets.push(s[i]);
                break;
            default:
                if (brackets.empty() || brackets.top() != symbols[s[i]])
                    return false;
                brackets.pop();
            }
            i++;
        }
        return brackets.empty();
    }
    void run()
    {
        cout << isValid("()[]{}") << endl;
    }
};