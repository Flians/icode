#include "../base/icode.hpp"
class L125 : public icode
{
public:
	void run() {
        cout << isPalindrome("") << " true" << endl;
        cout << isPalindrome("aa") << " true" << endl;
        cout << isPalindrome("A man, a plan, a canal: Panama") << " true" << endl;
        cout << isPalindrome("race a car") << " false" << endl;
    }

    bool is_alphanumeric(char &c) {
        if (c >= 'A' && c <= 'Z') {
            c = c -'A' + 'a';
            return true;
        }
        if ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))
            return true;
        return false;
    }
    
    bool isPalindrome(string s) {
        int l = 0, r = s.length()?s.length() - 1:0;
        while(l < r) {
            if (!is_alphanumeric(s[l])) {
                ++l; continue;
            }
            if (!is_alphanumeric(s[r])) {
                --r; continue;
            }
            if (s[l] != s[r]) break;
            ++l;
            --r;
        }
        return l >= r;
    }

    bool isPalindrome2(string s) {
        string news = "";
        int i = 0, len = s.length();
        for (; i<len; i++)
        {
            if ((s[i] >= 'a' && s[i] <='z') || (s[i] >= '0' && s[i] <='9'))
                news += s[i];
            if (s[i] >= 'A' && s[i] <='Z')
                news += (s[i] - 'A' + 'a');
        }
        len = news.length();
        for (i = 0; i < len/2; i++)
        {
            if (news[i] != news[len-i-1])
                return false;
        }
        return true;
    }
};