#include "../base/icode.hpp"
class L61 : public icode
{
public:
	void run() {
        print_res(rotateRight(create_list<int>({1,2,3,4,5}), 2));
        print_res(rotateRight(create_list<int>({1,2,3,4,5}), 2));
    }

    ListNode* rotateRight(ListNode* head, int k) {
        int len = 1;
        ListNode* tail = head;
        while (tail && tail->next) {
            ++len;
            tail= tail->next;
        }
        if (k%len == 0) {
            return head;
        }
        k = len - k%len;
        ListNode* root = head;
        while (k-- > 0) {
            ListNode* tmp= root->next;
            if (k == 0) {
                root->next = NULL;
            }
            root = tmp;
        }
        tail->next = head;
        return root;
    }
};