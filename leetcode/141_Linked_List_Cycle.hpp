#include "../base/icode.hpp"
class L141 : public icode
{
public:
    void run()
    {
        ListNode *head = create_list({3, 2, 0, -4});
        cout << hasCycle(head) << " false" << endl;
        print_res(head);
    }

    bool hasCycle_(ListNode *head)
    {
        ListNode *l1 = head;
        ListNode *l2 = head;
        do
        {
            if (l1 == NULL || l2 == NULL || l2->next == NULL)
                return false;
            l1 = l1->next;
            l2 = l2->next->next;
        } while (l1 != l2);
        return true;
    }

    bool hasCycle(ListNode *head)
    {
        ListNode *root = head, *last = nullptr;
        while (head)
        {
            ListNode *tmp = head->next;
            if (tmp == root)
                return true;
            head->next = last;
            last = head;
            head = tmp;
        }
        return false;
    }
};