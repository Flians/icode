#include "../base/icode.hpp"

class L2 : public icode
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *sum = new ListNode(0);
        ListNode *head = sum;
        int temp = 0;
        while (l1 || l2)
        {
            if (l1 && l2)
            {
                sum->next = new ListNode((l1->val + l2->val + temp) % 10);
                temp = (l1->val + l2->val + temp) / 10;
                l1 = l1->next;
                l2 = l2->next;
            }
            else if (l1 && !l2)
            {
                sum->next = new ListNode((l1->val + temp) % 10);
                temp = (l1->val + temp) / 10;
                l1 = l1->next;
            }
            else if (!l1 && l2)
            {
                sum->next = new ListNode((l2->val + temp) % 10);
                temp = (l2->val + temp) / 10;
                l2 = l2->next;
            }
            sum = sum->next;
        }
        if (temp)
            sum->next = new ListNode(temp);
        return head->next;
    }

    ListNode *addTwoNumbers_(ListNode *l1, ListNode *l2)
    {
        ListNode *res = new ListNode;
        ListNode *head = res;
        int temp = 0;
        while (l1 || l2)
        {
            res->next = new ListNode;
            res = res->next;
            if (l1)
            {
                temp += l1->val;
                l1 = l1->next;
            }
            if (l2)
            {
                temp += l2->val;
                l2 = l2->next;
            }
            res->val = temp % 10;
            temp /= 10;
        }
        if (temp > 0)
        {
            res->next = new ListNode(temp);
        }
        return head->next;
    }

    ListNode* addTwoNumbers__(ListNode* l1, ListNode* l2) {
        ListNode* root = new ListNode(0);
        ListNode* cur = root;
        int carry = 0;
        while(l1 || l2) {
            if (l1) {
                carry += l1->val; 
                if (l2) {
                    carry += l2->val;
                    l2 = l2->next;
                }
                l1 = l1->next;
            } else {
                carry += l2->val; 
                l2 = l2->next;
            }
            cur->next = new ListNode(carry%10);
            cur = cur->next;
            carry /= 10;
        }
        if (carry) {
            cur->next = new ListNode(carry);
        }
        cur = root->next;
        delete root;
        return cur;
    }

    void run()
    {
        print_res(addTwoNumbers__(create_list({5}), create_list({5})));
        print_res(addTwoNumbers__(create_list({2, 4, 3}), create_list({5, 6, 4})));
    }
};