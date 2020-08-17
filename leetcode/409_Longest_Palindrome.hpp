#include "../base/icode.hpp"
class L409 : public icode
{
public:
	void run() {
        cout << longestPalindrome("abccccdd") << " 7" << endl;
    }

    int longestPalindrome(string s) 
    {
        vector<int> v(128, 0);
        size_t ans=0;
        for(size_t i=0; i < s.size(); i++)
        {
            v[s[i]-'A']++;
            if(v[s[i]-'A']%2==0) {
                ans+=2;
                v[s[i]-'A'] = 0;
            }
        }
        return s.size()>ans ? ans+1 : ans;
    }
};