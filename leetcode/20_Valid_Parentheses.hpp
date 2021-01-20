#include "../base/icode.hpp"
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
    bool isValid_(string s)
    {
        stack<char> record;
        for (size_t i = 0, len = s.size(); i < len; ++i)
        {
            switch (s[i])
            {
            case ')':
                if (record.empty() || record.top() != '(')
                {
                    return false;
                }
                record.pop();
                break;
            case ']':
                if (record.empty() || record.top() != '[')
                {
                    return false;
                }
                record.pop();
                break;
            case '}':
                if (record.empty() || record.top() != '{')
                {
                    return false;
                }
                record.pop();
                break;
            default:
                record.push(s[i]);
            }
        }
        return record.empty();
    }
    void run()
    {
        cout << isValid("()[]{}") << endl;
    }
};