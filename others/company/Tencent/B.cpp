#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;
struct TrieNode
{
    TrieNode *children[26];
    bool is_end;
    int num;
    TrieNode()
    {
        this->num = 0;
        this->is_end = false;
        for (auto &item : children)
        {
            item = NULL;
        }
    }
};

void addWord(string word, TrieNode *root)
{
    TrieNode *tmp = root;
    for (auto &c : word)
    {
        if (!tmp->children[c - 'a'])
        {
            tmp->children[c - 'a'] = new TrieNode();
        }
        ++tmp->num;
        tmp = tmp->children[c - 'a'];
    }
    tmp->is_end = true;
}

string res;

bool search(int cur, int k, string str, TrieNode *root)
{
    if (cur == k) {
        res = str;
        return true;
    }
    for (int i = 0; i < 26; ++i)
    {
        if (root->children[i] && cur + root->children[i]->num >= k)
        {
            if (root->children[i]->is_end) {
                ++cur;
            }
            if (search(cur, k, str + (char)('a' + i), root->children[i])) {
                return true; 
            }
        } else {
            cur += root->children[i]->num;
        }
    }
    return false;
}

bool find_kth(string &s, int k)
{
    TrieNode *root = new TrieNode();
    for (int i = 0; i < s.length(); ++i)
    {
        for (int j = i; j < s.length(); ++j)
        {
            addWord(s.substr(i, j - i + 1), root);
        }
    }
    return search(0, k, "", root);
}

string solve(string &s, int k) {
    set<string> ss;
    int n = s.size();
    for(int i=0;i<n;i++){
        for(int j=1;j<=k&&i+j<=n;j++){
            ss.insert(s.substr(i,j));
        }
    } 
    for(int i=1;i<k;i++){
        ss.erase(ss.begin());
    }
    return *ss.begin();
}

int main()
{
    int k;
    string s;
    cin >> s;
    cin >> k;
    // find_kth(s, k);
    // cout << res << endl;
    cout << solve(s, k) << endl;
    return 0;
}