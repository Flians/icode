#include "../base/icode.hpp"
class L791 : public icode
{
public:
    void run()
    {
        std::cout << customSortString("cba", "abcd") << " cbad" << std::endl;
    }

    string customSortString(string order, string str)
    {
        int rank[26], ch[26], num[26] = {0}, i = 0;
        fill_n(rank, 26, -1);
        fill_n(ch, 26, -1);
        for (char c : order)
        {
            rank[c - 'a'] = i;
            ch[i++] = c - 'a';
        }
        for (char c : str)
        {
            if (rank[c - 'a'] == -1)
            {
                rank[c - 'a'] = i;
                ch[i++] = c - 'a';
            }
            ++num[rank[c - 'a']];
        }
        string res = "";
        for (int j = 0; j < i; ++j)
        {
            string tmp(num[j], ch[j] + 'a');
            res += tmp;
        }
        return res;
    }
};