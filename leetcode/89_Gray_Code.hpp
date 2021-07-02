#include "../base/icode.hpp"
class L89 : public icode
{
public:
    void run()
    {
        // [0,1,3,2]
        print_res(grayCode(2));
    }

    bool gray(int n, vector<int> &res, unordered_set<int> &vis)
    {
        if (res.size() == (size_t)(1 << n))
            return true;
        int cur = res.back();
        for (int i = 0; i < n; ++i)
        {
            int next = cur ^ (1 << i);
            if (vis.find(next) == vis.end())
            {
                res.push_back(next);
                vis.insert(next);
                if (gray(n, res, vis))
                {
                    return true;
                }
                res.pop_back();
                vis.erase(next);
            }
        }
        return false;
    }

    vector<int> grayCode(int n)
    {
        vector<int> res;
        unordered_set<int> vis;
        res.push_back(0);
        vis.insert(0);
        gray(n, res, vis);
        return res;
    }
};