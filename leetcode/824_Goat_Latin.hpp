#include "../base/icode.hpp"
class L824 : public icode
{
public:
	void run() {
        cout << toGoatLatin("I speak Goat Latin") << " Imaa peaksmaaa oatGmaaaa atinLmaaaaa" << endl;
    }

    string toGoatLatin(string S) {
        string res = "";
        int state = 0;
        string a = "a";
        string suffix = "";
        size_t i = 0;
        while (state != -1) {
            if (i == S.length()) {
                state = -1;
                if (res.length() > 0)
                    res += suffix + a;
            } else {
                if (state == 0) {
                    if (S[i] == ' ')
                        continue;
                    if (res.length() > 0)
                        res += " ";
                    switch(S[i]) {
                        case 'a':
                        case 'e':
                        case 'i':
                        case 'o':
                        case 'u':
                        case 'A':
                        case 'E':
                        case 'I':
                        case 'O':
                        case 'U':
                            res += S[i];
                            state = 1;
                            break;
                        default:
                            suffix = S[i];
                            state = 1;
                    }
                    suffix += "ma";
                } else {
                    if (S[i] == ' ') {
                        res += suffix + a;
                        a += 'a';
                        suffix = "";
                        state = 0;
                    } else {
                        res += S[i];
                    }
                }
            }
            ++i;
        }
        return res;
    }
};