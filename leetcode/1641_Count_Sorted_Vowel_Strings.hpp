#include "../base/icode.hpp"
class L1641 : public icode
{
public:
	void run() {
        cout << countVowelStrings(1) << " 5" << endl;
        cout << countVowelStrings(2) << " 15" << endl;
        cout << countVowelStrings(33) << " 66045" << endl;
    }

    void count(int remain, int last, int &res)
    {
        if (remain == 0) {
            ++res;
            return;
        }
        for (int i = last; i < 5; ++i) {
            count(remain-1, i, res);
        }
    }
    int countVowelStrings(int n) {
        int res = 0;
        for (int i = 0; i < 5; ++i)
            count(n-1, i, res);
        return res;
    }
};