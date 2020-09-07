#include <iostream>
#include <string>
using namespace std;
string fun(string &str, string &strips)
{
    string res(str.length() * 2 - strips.length(), ' ');
    int sl = 0, sr = str.length() - 1;
    int cl = 0, cr = strips.length() - 1;
    int rl = 0, rr = res.length() - 1;
    while (cl <= cr)
    {
        while (str[sl] != strips[cl])
        {
            res[rl++] = str[sl];
            res[rr--] = str[sl++];
        }
        while (str[sr] != strips[cr])
        {
            res[rl++] = str[sr];
            res[rr--] = str[sr--];
        }
        res[rl++] = str[sl++];
        res[rr--] = str[sr--];
        ++cl;
        --cr;
    }
    return res;
}

int main()
{
    string str, strips;
    cin >> str >> strips;
    cout << fun(str, strips) << endl;
}