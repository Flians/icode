#include "../base/icode.hpp"
class L438 : public icode
{
public:
	void run() {
        print_res(findAnagrams("abab", "ab"));
    }

    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        vector<int> item_p(26, 0);
        vector<int> item_match(26, 0);
        for (size_t i = 0; i < p.length(); ++i) {
            ++item_p[p[i] - 'a'];
        }
        int range = s.length() - p.length() + 1;
        for (int i = 0; i < range; ++i) {
            size_t j = 0;
            for (j = 0; j < p.length(); ++j) {
                ++item_match[s[i+j] - 'a'];
            }
            for (j = 0; j < 26; ++j) {
                if (item_p[j] != item_match[j])
                    break;
            }
            if (j == 26) res.emplace_back(i);
            vector<int>().swap(item_match);
            item_match.resize(26, 0);
        }
        return res;
    }
};