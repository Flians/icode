#include "../base/icode.hpp"
class L1662 : public icode
{
public:
	void run() {
        cout << arrayStringsAreEqual({"a", "bc"},{"ab", "c"}) << " true" << endl;
        cout << arrayStringsAreEqual({"a", "cb"},{"ab", "c"}) << " false" << endl;
    }

    bool arrayStringsAreEqual(vector<string>&& word1, vector<string>&& word2) {
        size_t i = 0, j = 0, k = 0, l = 0, num1 = word1.size(), num2 = word2.size();
        while(i < num1 || k < num2) {
            if (i < num1 && word1[i].size() <= j) {
                ++i; j = 0;
                continue;
            }
            if (k < num2 && word2[k].size() <= l) {
                ++k; l = 0;
                continue;
            }
            if (i >= num1 || k >= num2) {
                return false;
            }
            if (word1[i][j++] != word2[k][l++]) return false;
        }
        return true;
    }
};