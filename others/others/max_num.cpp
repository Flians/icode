/*
字符去重，但是要确保是最小字典序
*/
#include <iostream>
#include <map>
#include <stack>
#include <string>
using namespace std;

void method_2 (string str) {
    map<char, int> record;
    int i = 0, len = str.length();
    for (; i < len; i++)
    {
        record[str[i]] = i;
    }
    stack<char> res;
    map<char, bool> vis;
    for (i = 0; i < len; i++)
    {
        if (vis[str[i]]) continue;
        while (!res.empty() && record[res.top()] > i && res.top() >= str[i])
        {
            vis[res.top()] = false;
            res.pop();
        }
        res.push(str[i]);
        vis[res.top()] = true;
    }
    string resu = "";
    while (!res.empty())
    {
        resu = res.top() + resu;
        res.pop();
    }
    cout << resu << endl;
}

void method_1 (string str) {
    map<char, int> record;
    int i = 0, len = str.length();
    for (; i < len; i++)
    {
        if (record.count(str[i])==0)
        {
            record[str[i]] = 1;
        }
        else
        {
            ++record[str[i]];
        }
    }
    stack<char> res;
    map<char, bool> vis;
    for (i = 0; i < len; i++)
    {
        --record[str[i]];
        if (vis[str[i]]) continue;
        while (!res.empty() && record[res.top()] > 0 && res.top() >= str[i])
        {
            vis[res.top()] = false;
            res.pop();
        }
        res.push(str[i]);
        vis[res.top()] = true;
    }
    string resu = "";
    while (!res.empty())
    {
        resu = res.top() + resu;
        res.pop();
    }
    cout << resu << endl;
}

int main()
{
    string str;
    cin >> str;
    method_2(str);
    return 0;
}