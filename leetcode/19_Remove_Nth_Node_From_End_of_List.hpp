#include "../base/icode.hpp"

class L19 : public icode
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *pre = head;
        ListNode *begin = head;
        ListNode *end = head;
        while (n--)
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
    void run()
    {
        /*
1->2->3->4->5, and n = 2.
1->2->3->5
        */
    }
};