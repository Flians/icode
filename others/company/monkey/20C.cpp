#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> data;
    int num = 0, tmp = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> tmp;
        if (num == 0)
        {
            data.push_back(tmp);
            ++num;
        }
        else
        {
            if (data.back() == tmp)
            {
                if (num == m)
                {
                    data.pop_back();
                    num = 0;
                    int last = tmp;
                    while (cin >> tmp)
                    {
                        ++i;
                        if (tmp != last)
                        {
                            data.push_back(tmp);
                            num = 1;
                            break;
                        }
                    }
                }
                else
                {
                    ++num;
                }
            }
            else
            {
                while (--num)
                {
                    data.push_back(data.back());
                }
                data.push_back(tmp);
                num = 1;
            }
        }
    }
    while ((--num) > 0)
    {
        data.push_back(data.back());
    }
    cout << data[0];
    for (int i = 1; i < data.size(); ++i)
        cout << " " << data[i];
    cout << endl;
    return 0;
}