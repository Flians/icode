#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n + 1, 0);
    vector<int> r(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int x = n + 1;
    for (int i = n; i >= 1; i--)
    {
        r[i] = x;
        if (~a[i])
            x = i;
    }
    int i = 1, j, k, d, num1, num2, ans = 0;
    while (i <= n)
    {
        if (a[i] == -1)
        {
            j = r[i];
            k = r[j];
            if (j == n + 1)
            {
                ans++;
                break;
            }
            else
            {
                num1 = j - i;
            }
            num2 = k - j;
            if (k == n + 1)
            {
                ans++;
                break;
            }
            else
            {
                int flag = 0;
                if ((a[k] - a[j]) % (k - j) == 0)
                {
                    d = (a[k] - a[j]) / (k - j);
                    if (1ll * a[j] - 1ll * d * (j - i) > 0)
                        flag = 1;
                }
                if (flag)
                {
                    long long x = a[k];
                    for (i = k + 1; i <= n; i++)
                    {
                        x += d;
                        if (x <= 0)
                            break;
                        if (a[i] != -1 && a[i] != x)
                            break;
                    }
                    ans++;
                }
                else
                {
                    ans++;
                    i = k;
                }
            }
        }
        else
        {
            j = r[i];
            if (j == n + 1)
            {
                ans++;
                break;
            }
            else
            {
                num1 = j - i - 1;
            }
            int flag = 0;
            if ((a[j] - a[i]) % (j - i) == 0)
            {
                d = (a[j] - a[i]) / (j - i);
                flag = 1;
            }
            if (flag)
            {
                long long x = a[j];
                for (i = j + 1; i <= n; i++)
                {
                    x += d;
                    if (x <= 0)
                        break;
                    if (a[i] != -1 && a[i] != x)
                        break;
                }
                ans++;
            }
            else
            {
                i = j;
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}