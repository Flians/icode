#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool patternMatches(string pattern, string str) {
    int m =str.size(), n = pattern.size();
    vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
    dp[0][0] = 1;
    for (int j = 1; j < n && pattern[j] == '*'; j += 2) {
        dp[0][j+1] = 1;
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (pattern[j] == '*') {
                dp[i+1][j+1] = dp[i+1][j-1] || dp[i+1][j] || (dp[i][j+1] && pattern[j-1] == str[i]);
            } else {
                dp[i+1][j+1] = dp[i][j] && pattern[j] == str[i];
            }
        }
    }
    return dp[m][n];
}

bool patternMatches_(string pattern, string str) {
    int m =str.size(), n = pattern.size();
    vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
    dp[0][0] = 1;
    for (int j = 0; j < n && pattern[j] == '*'; ++j) {
        dp[0][j+1] = 1;
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (pattern[j] == '*') {
                dp[i+1][j+1] = dp[i+1][j] || dp[i][j+1];
            } else {
                dp[i+1][j+1] = dp[i][j] && pattern[j] == str[i];
            }
        }
    }
    return dp[m][n];
}

int main() {
    cout << patternMatches_("a*b", "aabb") << endl;
    cout << patternMatches_("a*b", "aabbc") << endl;
    cout << patternMatches_("ab*", "abcd") << endl;
    cout << patternMatches_("a*b*c", "abc") << endl;
    cout << patternMatches_("a*b*c", "aaabccc") << endl;
    cout << patternMatches_("a*b*c", "abca") << endl;
    return 0;
}