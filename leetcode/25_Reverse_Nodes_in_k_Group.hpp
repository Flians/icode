#include "../base/icode.hpp"
class L25 : public icode
{
public:
    void run()
    {
        // 1,2,3,4,5
        print_res(reverseKGroup(create_list({1, 2, 3, 4, 5}), 5));
    }

    ListNode *reverseKGroup(ListNode *head, int k)
    {
        int i = 0;
        ListNode *new_head = NULL, *last_tail = NULL, *cur_tail = head, *cur = head, *last = NULL;
        while (cur)
        {
            if ((++i) % k == 0)
            {
                if (!new_head)
                    new_head = cur;
                if (last_tail)
                    last_tail->next = cur;
                last_tail = cur_tail;
                if (cur->next)
                    cur_tail = cur->next;
            }
            ListNode *tmp = last;
            last = cur;
            cur = cur->next;
            last->next = tmp;
        }
        cur_tail->next = NULL;
        if (i % k == 0)
        {
            if (last_tail && last_tail != last && last_tail != cur_tail)
                last_tail->next = last;
        }
        else
        {
            while (last)
            {
                ListNode *tmp = cur;
                cur = last;
                last = last->next;
                cur->next = tmp;
            }
            if (last_tail)
                last_tail->next = cur_tail;
        }
        return new_head;
    }
};