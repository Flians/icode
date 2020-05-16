#include "../base/icode.hpp"

class L5 : public icode
{
public:
    int symmetry_around_centre(string s, int lcentre, int rcentre)
    {
        while(lcentre>=0 && rcentre<(int)s.size() && s.at(lcentre) == s.at(rcentre)){
            lcentre--;
            rcentre++;
        }
        return rcentre-lcentre-1;
    }

    string longestPalindrome(string s) {
        if(s.empty())
            return "";
        int i=0;
        int palin_len=0, len1=0, len2=0;
        int res_cen = 0, res_len = 0;
        for(; i<(int)s.size(); i++)
        {
            // around one point
            len1 = symmetry_around_centre(s, i, i);
            // symmetry
            len2 = symmetry_around_centre(s, i, i+1);
            palin_len = max(len1, len2);
            if(palin_len > res_len)
            {
                res_cen = i;
                res_len = palin_len;
            }
        }
        // start at begin = res_cen-(res_len-1)/2, and length is the value "res_len"
        return s.substr(res_cen-(res_len-1)/2, res_len);
    }

    void run()
    {
        cout << longestPalindrome("") << endl;
        cout << longestPalindrome("a") << endl;
        cout << longestPalindrome("ab") << endl;
        cout << longestPalindrome("aa") << endl;
        cout << longestPalindrome("abdbc") << endl;
        cout << longestPalindrome("abddbc") << endl;
    }
};