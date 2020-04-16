#include <iostream>
using namespace std;

int maxN = 1e+9 + 7;

int fun(int n)
{
    if (n == 1)
        return 2;
    int temp = fun(n / 2);
    if (n % 2 == 1)
        return temp * temp * 2 % maxN;
    else
        return temp * temp % maxN;
}

int main()
{
    int n;
    cin >> n;
    int res = fun(n-1) * n % maxN;
    cout << res << endl;
    return 0;
}