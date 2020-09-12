#include <iostream>
#include <stack>

using namespace std;

//递归版本
void quicksort(int a[], int l, int r)
{
    int mid = a[(l + r) / 2];
    int lwalker = l, rwalker = r;
    while (lwalker < rwalker)
    {
        while (a[lwalker] < mid)
            lwalker++;
        while (a[rwalker] > mid)
            rwalker--;
        if (lwalker <= rwalker)
        {
            int tmp = a[lwalker];
            a[lwalker] = a[rwalker];
            a[rwalker] = tmp;
            lwalker++;
            rwalker--;
        }
    }
    if (lwalker < r)
        quicksort(a, lwalker, r);
    if (rwalker > l)
        quicksort(a, l, rwalker);
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
    int lwalker, rwalker, mid;
    while (!s.empty())
    {
        int left = s.top();
        s.pop();
        int right = s.top();
        s.pop();
        lwalker = left;
        rwalker = right;
        mid = a[(lwalker + rwalker) / 2];
        while (lwalker < rwalker)
        {
            while (a[lwalker] < mid)
                lwalker++;
            while (a[rwalker] > mid)
                rwalker--;
            if (lwalker <= rwalker)
            {
                int tmp = a[lwalker];
                a[lwalker] = a[rwalker];
                a[rwalker] = tmp;
                lwalker++;
                rwalker--;
            }
        }
        if (lwalker < right)
            push2(s, lwalker, right);
        if (rwalker > left)
            push2(s, left, rwalker);
    }
}
//Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
};
// 单链表快排
ListNode *quickSortList(ListNode *head)
{
    if (!head || !head->next)
        return head;
    auto left = new ListNode(-1), mid = new ListNode(-1), right = new ListNode(-1);
    auto ltail = left, mtail = mid, rtail = right;
    int val = head->val;
    for (auto p = head; p; p = p->next)
    {
        if (p->val < val)
            ltail = ltail->next = p;
        else if (p->val == val)
            mtail = mtail->next = p;
        else
            rtail = rtail->next = p;
    }
    ltail->next = rtail->next = mtail->next = NULL;
    left->next = quickSortList(left->next);
    right->next = quickSortList(right->next);
    auto lh = left;
    while (lh->next)
        lh = lh->next;
    lh->next = mid->next;
    while (lh->next)
        lh = lh->next;
    lh->next = right->next;
    return left->next;
}

int main()
{
    int a[10] = {0, 6, 4, 2, 8, 1, 5, 3, 7, 9};
    //quicksort(a, 0, 9);
    qsort(a, 0, 9);
    for (int i = 0; i < 10; i++)
        cout << a[i] << " ";
    return 0;
}