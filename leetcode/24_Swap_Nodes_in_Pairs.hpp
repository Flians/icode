#include "../base/icode.hpp"
class L24 : public icode
{
public:
	void run() {
        // [2,1,4,3]
        print_res(swapPairs(create_list<ListNode>({1,2,3,4})));
    }

    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* second = head->next, *pre = new ListNode(0);
        ListNode* root = pre ;
        while (second) {
            head->next = second->next;
            second->next = head;
            pre->next = second;
            pre = head;
            head = head->next;
            if (head) {
                second = head->next;
            } else {
                second = NULL;
            }
        }
        head = root->next;
        root->next = NULL;
        delete root;
        return head;
    }

    ListNode* swapPairs_rec(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode* tmp = head->next->next;
        ListNode* second = head->next;
        second->next = head;
        head->next = swapPairs(tmp);
        return second;
    }
};