#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

long long Bound = 1000000000;
int T;

long long change(long long x)
{
    if (x >= 0) {
        x = x % Bound;
    } else
    {
        x = Bound - (0 - x) % Bound;
    }
    return x;
}

void fun_(long long &x, long long &y, string sub)
{
    for (int i = 0; i < sub.length() - 1; ++i)
    {
        switch (sub[i])
        {
        case 'N':
            --y;
            break;
        case 'S':
            ++y;
            break;
        case 'E':
            ++x;
            break;
        case 'W':
            --x;
            break;
        default:
            long long time_ = sub[i] - '0', x_ = 0, y_ = 0;
            string sub_;
            int temp = 1;
            i += 2;
            while (temp)
            {
                if (sub[i] == '(')
                    ++temp;
                if (sub[i] == ')')
                    --temp;
                sub_ += sub[i++];
            }
            --i;
            fun_(x_, y_, sub_);
            x += change(change(x_) * time_);
            y += change(change(y_) * time_);
            break;
        }
        x = change(x);
        y = change(y);
    }
}

int main()
{
    int i, j, index = 1;
    cin >> T;
    while (T--)
    {
        long long x = 0, y = 0;
        string move;
        cin >> move;
        fun_(x, y, move + ')');
        cout << "Case #" << (index++) << ": " << change(x)+1 << " " << change(y)+1 << endl;
    }
    return 0;
}