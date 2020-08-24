#include "../base/icode.hpp"

class StreamChecker : public icode
{
struct TrieNode
{
    TrieNode *children[26];
    bool is_end;
    TrieNode()
    {
        for (auto &item : children)
        {
            item = NULL;
        }
        is_end = false;
    }
};
private:
    TrieNode *root;
    vector<char> str;

public:
    StreamChecker() {
        this->root = new TrieNode();
    }

    StreamChecker(vector<string> &words)
    {
        this->root = new TrieNode();
        for (auto &word : words)
        {
            TrieNode *tmp = this->root;
            for (int i = word.length() - 1; i >= 0; --i)
            {
                if (!tmp->children[word[i] - 'a'])
                {
                    tmp->children[word[i] - 'a'] = new TrieNode();
                }
                tmp = tmp->children[word[i] - 'a'];
            }
            tmp->is_end = true;
        }
    }

    bool query(char letter)
    {
        str.push_back(letter);
        TrieNode *tmp = this->root;
        for (int i = str.size() - 1; i >= 0; i--)
        {
            int index = str[i] - 'a';
            tmp = tmp->children[index];
            if (tmp != NULL && tmp->is_end)
                return true;
            if (tmp == NULL)
                return false;
        }
        return false;
    }

    void run()
    {
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */