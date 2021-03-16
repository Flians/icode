#include "../base/icode.hpp"

class L160 : public icode
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *ca = headA, *cb = headB;
        int flag = 0;
        while (ca && cb)
        {
            if (ca == cb)
                return ca;

            if (ca->next)
                ca = ca->next;
            else if (flag < 2)
            {
                ca = headB;
                ++flag;
            }
            else
            {
                ca = NULL;
            }
            if (cb->next)
                cb = cb->next;
            else if (flag < 2)
            {
                cb = headA;
                ++flag;
            }
            else
            {
                cb = NULL;
            }
        }
        return NULL;
    }

    ListNode *getIntersectionNode_(ListNode *headA, ListNode *headB)
    {
        std::size_t la = 0, lb = 0;
        ListNode *ta = headA, *tb = headB;
        while (ta)
        {
            ++la;
            ta = ta->next;
        }
        while (tb)
        {
            ++lb;
            tb = tb->next;
        }
        if (la < lb)
        {
            lb -= la;
            while (lb--)
            {
                headB = headB->next;
            }
        }
        if (la > lb)
        {
            la -= lb;
            while (la--)
            {
                headA = headA->next;
            }
            la = lb;
        }
        while (la--)
        {
            if (headA == headB)
            {
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }
        return nullptr;
    }

    void run()
    {
        auto res = getIntersectionNode_(create_list({4, 1, 8, 4, 5}), create_list({5, 6, 1, 8, 4, 5}));
        std::cout << (res ? res->val : -1) << std::endl;
    }
};