#include <iostream>
#include <stack>

using namespace std;

//递归版本
void quicksort(int a[], int l, int r)
{
    int mid = a[(l+r) / 2];
    int lwalker = l, rwalker = r;
    while(lwalker < rwalker)
    {
        while(a[lwalker] < mid) lwalker++;
        while(a[rwalker] > mid) rwalker--;
        if(lwalker <= rwalker)
        {
            int tmp = a[lwalker];
            a[lwalker] = a[rwalker];
            a[rwalker] = tmp;
            lwalker++;
            rwalker--;
        }
    }
    if(lwalker < r) quicksort(a, lwalker, r);
    if(rwalker > l) quicksort(a, l, rwalker);
}

inline void push2(stack<int> &s, int l, int r)
{
    s.push(r);
    s.push(l);
}

//非递归，使用栈
void qsort(int a[], int l, int r)
{
    stack<int> s;
    push2(s, l, r);
    int lwalker,  rwalker, mid;
    while(!s.empty())
    {
        int left = s.top(); s.pop();
        int right = s.top(); s.pop();
        lwalker = left;
        rwalker = right;
        mid = a[(lwalker+rwalker)/2];
        while(lwalker < rwalker)
        {
            while(a[lwalker] < mid) lwalker++;
            while(a[rwalker] > mid) rwalker--;
            if(lwalker <= rwalker)
            {
                int tmp = a[lwalker];
                a[lwalker] = a[rwalker];
                a[rwalker] = tmp;
                lwalker++;
                rwalker--;
            }
        }
        if(lwalker < right) push2(s, lwalker, right);
        if(rwalker > left) push2(s, left, rwalker);
    }
}

int main()
{
    int a[10] = {0, 6,4,2,8,1,5,3,7,9};
    //quicksort(a, 0, 9);
    qsort(a, 0, 9);
    for(int i=0; i<10; i++)
        cout << a[i] << " ";
    return 0;
}