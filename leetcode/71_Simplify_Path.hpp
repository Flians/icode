#include "../base/icode.hpp"
class L71 : public icode
{
public:
    void run()
    {
        cout << simplifyPath("/..") << " /" << endl;
        cout << simplifyPath("/../") << " /" << endl;
        cout << simplifyPath("/a/./b/../..//c/") << " /c" << endl;
    }

    string simplifyPath(string path)
    {
        string item;
        vector<string> items;
        for (size_t i = 0, len = path.size(); i < len; ++i)
        {
            switch (path[i])
            {
            case '/':
                if (item.empty() || item == "/" || item == ".")
                {
                }
                else if (item == "..")
                {
                    if (!items.empty())
                    {
                        items.pop_back();
                    }
                }
                else
                {
                    items.emplace_back(item);
                }
                item = "";
                break;
            case '.':
                item += '.';
                break;
            default:
                item += path[i];
            }
        }
        if (item.empty() || item == "/" || item == ".")
        {
        }
        else if (item == "..")
        {
            if (!items.empty())
            {
                items.pop_back();
            }
        }
        else
        {
            items.emplace_back(item);
        }
        string res;
        for (auto &item : items)
        {
            res += "/" + item;
        }
        return res.empty() ? "/" : res;
    }
};