#include "../base/icode.hpp"
class L82 : public icode
{
public:
	void run() {
        // [1,2,5]
        print_res(deleteDuplicates(create_list({1,2,3,3,4,4,5})));
        // [2]
        print_res(deleteDuplicates(create_list({1,1,2,5,5})));
    }

    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *root = new ListNode();
        ListNode *last = root, *cur = head;
        while (head) {
            head = head->next;
            bool flag = false;
            while (head && cur->val == head->val) {
                head = head->next;
                flag = true;
            }
            if (!flag) {
                last->next = cur;
                last = last->next;
            }
            cur = head;
        }
        if (last && last->next) {
            head = last->next;
            last->next = NULL;
            while (head) {
                cur = head->next;
                delete head;
                head = cur;
            }
        }
        head = root->next;
        delete root;
        return head;
    }
};