#include "../base/icode.hpp"
class L763 : public icode
{
public:
	void run() {
        print_res(partitionLabels("ababcbacadefegdehijhklij")); // 9, 7, 8
    }

    vector<int> partitionLabels(string S) {
        size_t ch[26];
        for (size_t i = 0; i < S.length(); ++i) {
            ch[S[i]-'a'] = i;
        }
        vector<int> res;
        size_t first = 0;
        size_t maxi = 0;
        for (size_t i = 0; i < S.length(); ++i) {
            maxi = max(maxi, ch[S[i]-'a']);
            if (i == maxi) {
                res.push_back(i-first+1);
                first = i + 1;
            }
        }
        return res;
    }
};