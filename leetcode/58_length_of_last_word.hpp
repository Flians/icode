#include "../base/icode.hpp"
/*
 * @lc app=leetcode id=58 lang=cpp
 *
 * [58] Length of Last Word
 */

// @lc code=start
class L58 : public icode
{
public:
	void run() {
        cout << lengthOfLastWord("") << endl;
        cout << lengthOfLastWord(" ") << endl;
        cout << lengthOfLastWord("Hello World") << endl;
    }

    int lengthOfLastWord(string s)
    {
        string str = "";
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (s[i] != ' ')
            {
                str += s[i];
            }
            else
            {
                if (str.size() > 0)
                {
                    return str.size();
                }
            }
        }
        return str.size();
    }
};
// @lc code=end
