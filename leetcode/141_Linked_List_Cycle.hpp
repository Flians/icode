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