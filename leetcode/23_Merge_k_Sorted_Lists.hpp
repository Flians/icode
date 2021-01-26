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

    ListNode *mergeKLists_(vector<ListNode *> &&lists)
    {
        auto cmp = [](pair<ListNode *, int> &a, pair<ListNode *, int> &b) {
            if (a.first && b.first)
            {
                return a.first->val == b.first->val ? a.second > b.second : a.first->val > b.first->val;
            }
            else
            {
                return a.first == nullptr;
            }
        };
        priority_queue<pair<ListNode *, int>, vector<pair<ListNode *, int>>, decltype(cmp)> record(cmp);
        size_t k = lists.size();
        ListNode *root = new ListNode(-1);
        ListNode *cur = root;
        //init
        for (size_t i = 0; i < k; ++i)
        {
            if (lists[i])
            {
                record.emplace(lists[i], i);
                lists[i] = lists[i]->next;
            }
        }
        while (!record.empty())
        {
            auto tmp = record.top();
            record.pop();
            if (tmp.first)
            {
                cur->next = tmp.first;
                cur = tmp.first;
                if (lists[tmp.second])
                {
                    record.emplace(lists[tmp.second], tmp.second);
                    lists[tmp.second] = lists[tmp.second]->next;
                }
            }
        }
        cur->next = nullptr;
        cur = root;
        root = root->next;
        delete cur;
        return root;
    }

    void run()
    {
        //1->1->2->3->4->4->5->6
        print_res(mergeKLists_({create_list({1, 4, 5}), create_list({1, 3, 4}), create_list({2, 6})}));
    }
};