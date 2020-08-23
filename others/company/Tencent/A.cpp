#include <iostream>
#include <vector>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *removeKthFromEnd(ListNode *head, int k)
{
    ListNode *pre = head;
    ListNode *begin = head;
    ListNode *end = head;
    while (k--)
    {
        end = end->next;
    }
    while (end != NULL)
    {
        pre = begin;
        begin = begin->next;
        end = end->next;
    }
    if (head == begin)
    {
        head = begin->next;
    }
    else if (begin->next == NULL)
    {
        pre->next = NULL;
    }
    else
    {
        pre->next = begin->next;
    }
    delete begin;
    return head;
}

ListNode *create_list(vector<int> &nums) {
    ListNode *head = new ListNode(nums[0]);
    ListNode *tmp = head;
    for (int i = 1; i < nums.size(); ++i) {
        ListNode *next = new ListNode(nums[i]);
        tmp->next = next;
        tmp = next;
    }
    return head;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    ListNode *head = create_list(nums);
    head = removeKthFromEnd(head, n-k+1);
    cout << head->val;
    while (head->next)
    {
        head = head->next;
        cout << " " << head->val;
    }
    cout << endl;
    return 0;
}