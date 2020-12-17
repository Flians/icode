#include "../base/icode.hpp"
class L131 : public icode
{
public:
	void run() {
        // [["a","a","b"],["aa","b"]]
        print_res(partition("aab"));
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> cur;
        // dfs(res, s, 0,  cur);

        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), 0));
        dfs_dp(res, s, 0,  cur, dp);
        
        return res;
    }
    
    void dfs(vector<vector<string>> &res, string & s, int begin, vector<string> cur) {
        int len = s.size();
        if (begin >= len) {
            res.push_back(cur);
        }
        for (int end = begin; end < len; ++end) {
            if (is_palind(s, begin, end)) {
                cur.push_back(s.substr(begin, end-begin+1));
                dfs(res, s, end + 1,  cur);
                cur.pop_back();
            }
        }
    }
    bool is_palind(string &s, int l, int h) {
        while (l < h) {
            if (s[l++] != s[h--])
                return false;
        }
        return true;
    }

    void dfs_dp(vector<vector<string>> &res, string & s, int begin, vector<string> cur, vector<vector<bool>> &dp) {
        int len = s.size();
        if (begin >= len) {
            res.push_back(cur);
        }
        for (int end = begin; end < len; ++end) {
            if (s[begin] == s[end] && (end - begin <= 2 || dp[begin + 1][end - 1])) {
                dp[begin][end] = true;
                cur.push_back(s.substr(begin, end-begin+1));
                dfs_dp(res, s, end + 1,  cur, dp);
                cur.pop_back();
            }
        }
    }
};