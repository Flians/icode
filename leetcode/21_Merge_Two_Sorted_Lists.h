#include "../base/icode.h"

class L21 : public icode
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *new_node = new ListNode(0);
        ListNode *temp = new_node;
        while (l1 != NULL || l2 != NULL)
        {
            if (l1 == NULL)
            {
                temp->next = l2;
                break;
            }
            if (l2 == NULL)
            {
                temp->next = l1;
                break;
            }
            if (l1->val <= l2->val)
            {
                temp->next = l1;
                l1 = l1->next;
            }
            else
            {
                temp->next = l2;
                l2 = l2->next;
            }
            temp = temp->next;
        }
        return new_node->next;
    }
    void run()
    {
        /*
Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
        */
    }
};