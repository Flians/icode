#include "../base/icode.hpp"
class L234 : public icode
{
public:
    void run()
    {
        cout << isPalindrome(create_list({1, 2, 2, 1})) << " true" << endl;
        cout << isPalindrome(create_list({1, 2})) << " false" << endl;
    }

    bool isPalindrome(ListNode *head)
    {
        ListNode *fast = head, *slow = head;
        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *tmp, *pre = nullptr;
        while (slow)
        {
            tmp = slow->next;
            slow->next = pre;
            pre = slow;
            slow = tmp;
        }
        while (pre)
        {
            if (pre->val != head->val)
                return false;
            head = head->next;
            pre = pre->next;
        }
        return true;
    }
};