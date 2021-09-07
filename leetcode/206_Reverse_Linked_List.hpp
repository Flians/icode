#include "../base/icode.hpp"
class L206 : public icode
{
public:
	void run() {}

    ListNode* reverseList(ListNode* head) {
        ListNode* last = NULL, *tmp = NULL;
        while (head) {
            tmp = head->next;
            head->next = last;
            last = head;
            head = tmp;
        }
        return last;
    }
};