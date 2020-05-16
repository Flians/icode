#include "../base/icode.hpp"

class L160 : public icode {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *ca = headA, *cb = headB;
        int flag=0;
        while (ca && cb) {
            if (ca==cb)
                return ca;
            
            if (ca->next)
                ca = ca->next;
            else if(flag <2) {
                ca = headB;
                ++flag;
            } else {
                ca = NULL;
            }
            if (cb->next)
                cb = cb->next;
            else if(flag <2) {
                cb = headA;
                ++flag;
            } else {
                cb = NULL;
            }
        }
        return NULL;
    }

    void run() {
        
    }
};