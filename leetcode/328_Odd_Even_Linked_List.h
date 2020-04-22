#include "../base/icode.h"

class L328 : public icode
{
public:
    ListNode *oddEvenList(ListNode *head)
    {
        if (!head)
            return head;
        ListNode *hodd = head;
        head = head->next;
        if (!head)
            return hodd;
        ListNode *heven = head;
        head = head->next;
        ListNode *odd = hodd, *even = heven;
        while (head)
        {
            odd->next = head;
            odd = odd->next;
            head = head->next;
            if (head)
            {
                even->next = head;
                even = even->next;
                head = head->next;
            }
        }
        odd->next = heven;
        even->next = NULL;
        return hodd;
    }

    void run() {
        /* 
        Input: 2->1->3->5->6->4->7->NULL
        Output: 2->3->6->7->1->5->4->NULL
        */
    }
};