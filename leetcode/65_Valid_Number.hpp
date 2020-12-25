#include "../base/icode.hpp"
class L65 : public icode
{
public:
    void run() {
        cout << isNumber("005047e+6") << " true" << endl;
        cout << isNumber(" -.") << " false" << endl;
        cout << isNumber("..") << " false" << endl;
        cout << isNumber("+.8") << " true" << endl;
        cout << isNumber("-1.") << " true" << endl;
        cout << isNumber(".1.") << " false" << endl;
        cout << isNumber("3. ") << " true" << endl;
        cout << isNumber(".1") << " false" << endl;
        cout << isNumber("0e") << " false" << endl;
        cout << isNumber("e1") << " false" << endl;
        cout << isNumber("e") << " false" << endl;
        cout << isNumber("   ") << " false" << endl;
        cout << isNumber("0") << " false" << endl;
        cout << isNumber("1 ") << " false" << endl;
    }

    bool isNumber(string&& s) {
        int l = 0, r = s.size(), state = 0;
        bool flag = false, flag_p = true, flag_e = true;
        for (; l < r; ++l) {
            switch (state) {
                case 0:
                    if (s[l] == ' ') continue;
                    else if (s[l] == '+' || s[l] == '-') state = 1;
                    else if (s[l] == '.') { state = 1; flag_p = false; }
                    else if (s[l] >= '0' && s[l] <= '9') { state = 2; flag = true; }
                    else return false;
                    break;
                case 1:
                    if (s[l] >= '0' && s[l] <= '9') { state = 2; flag = true; }
                    else if (s[l] == '.' && flag_p) { state = 1; flag_p = false; }
                    else return false;
                    break;
                case 2:
                    if (s[l] >= '0' && s[l] <= '9') { flag = true; continue; }
                    else if (s[l] == '.' && flag_e && flag_p) flag_p = false;
                    else if (s[l] == 'e' && flag_e) { flag_e = false; flag = false; }
                    else if ((s[l] == '+' || s[l] == '-') && !flag_e && !flag) continue;
                    else if (s[l] == ' ') state = 3;
                    else return false;
                    break;
                case 3:
                    if (s[l] == ' ') continue;
                default:
                    return false;
            }
        }
        return flag;
    }
};