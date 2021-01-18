#include "../base/icode.hpp"

class L215 : public icode
{
public:
    void get_elem_rand(vector<int> *nums)
    {
        srand((unsigned)time(NULL));
        int id = rand() % (*nums).size();
        swap((*nums).at(0), (*nums).at(id));
    }

    int findKthLargest(vector<int> &&nums, int k)
    {
        get_elem_rand(&nums);
        int povit = nums.front();
        vector<int> lnums, rnums;
        for (vector<int>::const_iterator iter = nums.begin() + 1; iter != nums.end(); iter++)
        {
            if (*iter >= povit)
                lnums.push_back(*iter);
            else
                rnums.push_back(*iter);
        }
        if ((int)lnums.size() == k - 1)
            return povit;
        else if ((int)lnums.size() < k - 1)
            return findKthLargest(move(rnums), k - lnums.size() - 1);
        else
            return findKthLargest(move(lnums), k);
    }

    int findKthLargest_(vector<int> &&nums, int k)
    {
        bool flag = false;
        priority_queue<int, vector<int>, greater<int>> kth;
        for (int i : nums)
        {
            kth.emplace(i);
            if (flag || (int)kth.size() > k)
            {
                flag = true;
                kth.pop();
            }
        }
        return kth.top();
    }

    void run()
    {
        cout << findKthLargest_({3, 2, 3, 1, 2, 4, 5, 5, 6}, 4) << " 4" << endl;
    }
};