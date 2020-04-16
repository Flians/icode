#include <iostream>
#include <string>
#include <limits.h>
using namespace std;

// a>=0, b>=0
string add(int a, int b)
{
    string res = "0";
    int i = 0, temp = 0;
    while (a != 0 || b != 0)
    {
        temp = a % 10;
        temp += b % 10;
        res[i++] += temp % 10;
        if (temp / 10)
            res = (char)(temp / 10 + '0') + res;
        a /= 10;
        b /= 10;
    }
    return res;
}

// a>=0, b<0, abs(a) > abs(b)
string oadd(int a, int b)
{
    string res;
    int temp = 0;
    while (a != 0 || b != 0)
    {
        temp = a % 10;
        temp -= b % 10;
        while (temp < 0)
        {
            temp += 10;
            a -= 10;
        }
        res = (char)(temp + '0') + res;
        a /= 10;
        b /= 10;
    }
    return res;
}

int main()
{
    int a, b;
    while (cin >> a >> b)
    {
        bool flag = false;
        string res;
        if (a == 0 || b == 0)
        {
            res = a == 0 ? to_string(b) : to_string(a);
        }
        else if (a < 0 && b < 0)
        {
            if (a > b)
            {
                swap(a, b);
            }
            a += 1;
            b -= 1;
            a *= -1;
            b *= -1;
            flag = true;
            res = add(a, b);
        }
        else if (a > 0 && b > 0)
        {
            res = add(a, b);
        }
        else
        {
            if (a == INT_MIN)
            {
                a += 1;
                b -= 1;
            }
            if (b == INT_MIN)
            {
                a -= 1;
                b += 1;
            }
            if (abs(a) < abs(b))
            {
                if (b < 0)
                    flag = true;
                swap(a, b);
            }
            else if (a < 0)
            {
                flag = true;
            }
            a = abs(a);
            b = abs(b);
            res = oadd(a, b);
        }
        if (flag)
            cout << "-";
        cout << res << endl;
    }
    return 0;
}