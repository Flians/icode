#include "../base/icode.hpp"

class L21 : public icode
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *root = new ListNode(0);
        ListNode *cur = root;
        while (l1 || l2) {
            if (l1) {
                if (l2) {
                    if (l1->val <= l2->val) {
                        cur->next = l1;
                        cur = l1;
                        l1 = l1->next;
                    } else {
                        cur->next = l2;
                        cur = l2;
                        l2 = l2->next;
                    }
                } else {
                    cur->next = l1;
                    break;
                }
            } else {
                cur->next = l2;
                break;
            }
        }
        cur = root->next;
        delete root;
        return cur;
    }
    void run()
    {
        // [1,1,2,3,4,4]
        print_res(mergeTwoLists(create_list({1,2,4}), create_list({1,3,4})));
    }
};