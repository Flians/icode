#include "../base/icode.hpp"
class L1721 : public icode
{
public:
    void run()
    {
        print_res(swapNodes(create_list({1, 2, 3, 4, 5}), 2));
    }

    ListNode *swapNodes(ListNode *head, int k)
    {
        if (!head)
            return head;
        std::vector<ListNode *> nodes;
        while (head)
        {
            nodes.emplace_back(head);
            head = head->next;
        }
        std::swap(nodes[k - 1]->val, nodes[nodes.size() - k]->val);
        return nodes.front();
    }
};