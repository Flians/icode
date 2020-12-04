#include "../base/icode.hpp"
class L382 : public icode
{
private:
    ListNode* head;
public:
	void run() {
        // 水塘抽样
    }
    L382() {}
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    L382(ListNode* head) {
        this->head = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int i = 1, res = 0;
        ListNode* cur = this->head;
        while (cur) {
            if (rand()*1.0/RAND_MAX < 1.0/i) {
                res = cur->val;
            }
            ++i;
            cur = cur->next;
        }
        return res;
    }
};