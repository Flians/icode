#include "../base/icode.hpp"
class L1291 : public icode
{
public:
    void run()
    {
        print_res(sequentialDigits(1000, 13000)); // [1234,2345,3456,4567,5678,6789,12345]
    }

    vector<int> sequentialDigits(int low, int high)
    {
        string s = "123456789";
        vector<int> v;
        for (size_t i = 0; i < s.length(); i++)
        {
            for (size_t j = i; j < s.length(); j++)
            {
                string sub = s.substr(i, j - i + 1);
                int ans = stoi(sub);
                if (ans >= low and ans <= high)
                {
                    v.push_back(ans);
                }
            }
        }
        sort(v.begin(), v.end());
        return v;
    }
};