#include "../base/icode.hpp"
class L916 : public icode
{
public:
    void run()
    {
        // ["facebook","leetcode"]
        print_res(wordSubsets({"amazon", "apple", "facebook", "google", "leetcode"}, {"ec", "oc", "ceo"}));
    }

    vector<string> wordSubsets(vector<string> &&A, vector<string> &&B)
    {
        int *num_b = new int[26]{0};
        for (auto &i : B)
        {
            int *item = count(i);
            for (int i = 0; i < 26; ++i)
            {
                num_b[i] = max(num_b[i], item[i]);
            }
        }
        std::vector<std::string> res;
        for (auto &i : A)
        {
            bool flag = true;
            int *item = count(i);
            for (int i = 0; i < 26; ++i)
            {
                if (num_b[i] > item[i])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
                res.emplace_back(i);
        }
        return res;
    }

    int *count(std::string &word)
    {
        int *nums = new int[26]{0};
        for (char i : word)
        {
            ++nums[i - 'a'];
        }
        return nums;
    }
};