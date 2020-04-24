#include "../base/icode.h"

class L3: public icode
{
public:
    int fun_BF(string s) {
        int len = s.length();
        if(len==0)
            return 0;
        int begin=0, end=0, length=1,temp=0;
        for(;begin < len-1; begin++)
        {
            for(end=begin+1; end<len; end++)
            {
                for(temp=end-1; temp>=begin;temp--)
                {
                    if(s[end]==s[temp])
                        break;
                }
                if(temp != begin-1)
                    break;
            }
            length = max(length, end-begin);
        }
        return length;
    }
    
    int fun_SW(string s) {
        int len = s.length();
        if(len==0)
            return 0;
         map<char, int> sub;
        int i=0,j=0,res=0;
        for (; j<len; ++j) {
            if (sub.count(s[j])) {
                i = max(i, sub[s[j]]+1);
            }
            sub[s[j]] = j;
            res = max(j-i+1, res);
        }
        return res;
    }
    
    int lengthOfLongestSubstring(string s) {
        return fun_SW(s);
    }

    void run() {
        cout << lengthOfLongestSubstring("tmmzuxt") << endl;
    }
};