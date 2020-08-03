#include "../base/icode.hpp"
class L567 : public icode
{
public:
	void run() {
        cout << checkInclusion("ab", "eidbaooo") << " true" << endl;
    }

    bool checkInclusion(string s1, string s2) {
        vector<int> item1(26, 0);
        vector<int> item2(26, 0);
        for (size_t i = 0; i < s1.length(); ++i) {
            ++item1[s1[i] - 'a'];
        }
        int range = s2.length() - s1.length() + 1;
        for (int i = 0; i < range; ++i) {
            size_t j = 0;
            for (j = 0; j < s1.length(); ++j) {
                ++item2[s2[i+j] - 'a'];
            }
            for (j = 0; j < 26; ++j) {
                if (item1[j] != item2[j])
                    break;
            }
            if (j == 26) return true;
            vector<int>().swap(item2);
            item2.resize(26, 0);
        }
        return false;
    }
};