#include "../base/icode.hpp"
class L775 : public icode
{
public:
    void run()
    {
        cout << isIdealPermutation({1, 0, 2}) << " true" << endl;
        cout << isIdealPermutation({1, 2, 0}) << " false" << endl;
    }

    bool isIdealPermutation(vector<int> &&A)
    {
        for (int i = 0, n = A.size(); i < n; i++)
        {
            if (abs(A[i] - i) > 1)
                return false;
        }
        return true;
    }
};