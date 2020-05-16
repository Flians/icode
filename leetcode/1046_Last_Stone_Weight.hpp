#include "../base/icode.hpp"

class L1046 : public icode
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        priority_queue<int, vector<int>, less<int>> maxq;
        for (auto stone : stones)
        {
            maxq.push(stone);
        }
        int x = 0, y = 0;
        while (maxq.size() > 1)
        {
            y = maxq.top();
            maxq.pop();
            x = maxq.top();
            maxq.pop();
            if (x != y)
                maxq.push(y - x);
        }
        if (maxq.empty())
            return 0;
        return maxq.top();
    }

    void run()
    {
        int a[6] = {2,7,4,1,8,1};
        vector<int> ilist(a, a+6);
        cout << lastStoneWeight(ilist) << endl;
    }
};
