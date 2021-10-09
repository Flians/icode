#include "../base/icode.hpp"
class L2030 : public icode
{
public:
    void run()
    {
        std::cout << smallestSubsequence("leetcode", 4, 'e', 2) << "ecde" << std::endl;
    }

    string smallestSubsequence(string s, int k, char letter, int repetition)
    {
        int n = s.size(), num = 0;
        for (int i = 0; i < n; ++i)
        {
            num += (s[i] == letter);
        }
        string res;
        int tmp_n = 0;
        for (int i = 0; i < n; ++i)
        {
            while (tmp_n > 0 && res.back() > s[i] && n - i - 1 + tmp_n >= k && (res.back() != letter || num > repetition))
            {
                if (res.back() == letter)
                {
                    ++repetition;
                }
                res.pop_back();
                --tmp_n;
            }
            if (tmp_n < k)
            {
                if (s[i] == letter)
                {
                    res.push_back(letter);
                    ++tmp_n;
                    --repetition;
                }
                else if (k - tmp_n - repetition > 0)
                {
                    res.push_back(s[i]);
                    ++tmp_n;
                }
            }
            if (s[i] == letter)
            {
                --num;
            }
        }
        return res;
    }
};