#include <iostream>
#include <vector>

using namespace std;

int n, A, B;
double p, q;

void fun(int index, int sub, vector<int> a)
{
    if (index == n)
    {
        A += sub;
        ++B;
    } else
    {
        fun(index+1, sub, a);
        fun(index+1, sub+a[index], a);
    }
}

int main() {
    A=B=0;
    cin >> n >> p >> q;
    vector<int> a(n, 0);
    int i=0;
    while (i<n)
    {  
        cin >> a[i++];
    }
    fun(0, 0, a);
    cout << A/B << endl;
    return 0;
}