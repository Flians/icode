#include <iostream>
#include <vector>

using namespace std;

int num, n;

bool funny(vector<int> cur) {
    bool flag = true;
    if (cur.empty())
        return false;
    for (int i=1; i<=cur.size(); ++i) {
        cout << cur[i-1] << " ";
        if (cur[i-1]%i!=0) {
            flag = false;
            break;
        }
    }
    cout << (flag?"Y":"N") << endl;
    return flag;
}

void fun(int index, vector<int> cur, vector<int> a)
{
    if (index == n)
    {
        if (funny(cur))
            num++;
    } else
    {
        fun(index+1, cur, a);
        cur.push_back(a[index]);
        fun(index+1, cur, a);
    }
}

int main() {
    num = 0;
    cin >> n;
    vector<int> a(n, 0);
    int i=0;
    while (i<n)
    {  
        cin >> a[i++];
    }
    vector<int> cur;
    fun(0, cur, a);
    cout << num << endl;
    return 0;
}