#include "../base/icode.hpp"

class L23 : public icode
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.empty())
            return NULL;
        int min, index = 0;
        int j = 0;
        bool flag = true;
        ListNode *result;
        ListNode *now = (ListNode *)malloc(sizeof(ListNode));
        for (vector<ListNode *>::iterator iter = lists.begin(); iter != lists.end();)
        {
            if (*iter == NULL)
            {
                lists.erase(iter);
            }
            else
            {
                iter++;
            }
        }
        while (!lists.empty())
        {
            min = INT_MAX;
            for (j = 0; j < (int)lists.size(); j++)
            {
                if (min >= lists[j]->val)
                {
                    index = j;
                    min = lists[j]->val;
                }
            }
            if (flag)
            {
                result = lists[index];
                flag = false;
            }
            now->next = lists[index];
            now = now->next;
            if (lists[index]->next != NULL)
                lists[index] = lists[index]->next;
            else
                lists.erase(lists.begin() + index);
        }
        return flag ? NULL : result;
    }
    void run()
    {
        /*
Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6
        */
    }
};