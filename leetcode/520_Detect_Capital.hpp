#include "../base/icode.hpp"
class L520 : public icode
{
public:
	void run() {
        cout << detectCapitalUse("USA") << " True" << endl;
        cout << detectCapitalUse("FlaG") << " False" << endl;
        cout << detectCapitalUse("Leetcode") << " True" << endl;
    }

    bool detectCapitalUse(string word) {
        bool res = true;
        if (word[0] >= 'A' && word[0] <= 'Z') {
            int time = 0;
            for (size_t i = 1; i < word.length(); ++i) {
                if (word[i] >= 'A' && word[i] <= 'Z') {
                    if (time > 0) {
                        res = false;
                        break;
                    }
                    time = -1;
                }
                if (word[i] >= 'a' && word[i] <= 'z') {
                    if (time == -1) {
                        res = false;
                        break;
                    }
                    ++time;
                }
            }
        } else {
            for (size_t i = 1; i < word.length(); ++i) {
                if (word[i] >= 'A' && word[i] <= 'Z') {
                    res = false;
                    break;
                }
            }
        }
        return res;
    }
};