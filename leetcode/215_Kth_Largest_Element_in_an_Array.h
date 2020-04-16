#include "../base/icode.h"

class L215 : public icode
{
public:
    void get_elem_rand(vector<int> *nums)
    {
        srand((unsigned)time(NULL));
        int id = rand() % (*nums).size();
        swap((*nums).at(0), (*nums).at(id));
    }

    int findKthLargest(vector<int> &nums, int k)
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
        if (lnums.size() == k - 1)
            return povit;
        else if (lnums.size() < k - 1)
            return findKthLargest(rnums, k - lnums.size() - 1);
        else
            return findKthLargest(lnums, k);
    }

    void run()
    {
    }
};