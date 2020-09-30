#include "../base/icode.hpp"
class L139 : public icode
{
public:
	void run() {
        vector<string> wordDict = {"apple", "pen"};
        cout << wordBreak("applepenapple", wordDict) << " true" << endl;
        wordDict = {"cats", "dog", "sand", "and", "cat"};
        cout << wordBreak("catsandog", wordDict) << " false" << endl;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size() + 1, 0);
        dp[0] = 1; 
        for (size_t i = 0; i < s.length(); ++i) {
            if (!dp[i])
                continue;
            for (auto &item : wordDict) {
                size_t len = item.length() + i;
                if (len <= s.length() && s.substr(i, item.length()) == item) {
                    dp[len] = 1;
                }
            }
        }
        return dp.back();
    }
};