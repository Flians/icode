#include "../base/icode.hpp"
class L143 : public icode
{
public:
	void run() {
        // 1->2->3->4, reorder to 1->4->2->3.
        // 1->2->3->4->5, reorder it to 1->5->2->4->3.
    }

    void reorderList(ListNode* head) {
        vector<int> vals;
        ListNode* tmp = head;
        while (tmp) {
            vals.push_back(tmp->val);
            tmp = tmp->next;
        }
        for (size_t i = 0; i < vals.size()/2; ++i) {
            head->val = vals[i];
            head->next->val = vals[vals.size() - i -1];
            head = head->next->next;
        }
        if (vals.size()%2 == 1) {
            head->val = vals[vals.size()/2];
        }
    }
};