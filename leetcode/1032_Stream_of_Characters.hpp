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

    virtual ~StreamChecker() {
        delete root;
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
        vector<string> words = {"cd","f","kl"};
        StreamChecker *streamChecker = new StreamChecker(words); // init the dictionary.
        cout << streamChecker->query('a') << " false" << endl;          // return false
        cout << streamChecker->query('b') << " false" << endl;          // return false
        cout << streamChecker->query('c') << " false" << endl;          // return false
        cout << streamChecker->query('d') << " true" << endl;           // return true, because 'cd' is in the wordlist
        cout << streamChecker->query('e') << " false" << endl;          // return false
        cout << streamChecker->query('f') << " true" << endl;           // return true, because 'f' is in the wordlist
        cout << streamChecker->query('g') << " false" << endl;          // return false
        cout << streamChecker->query('h') << " false" << endl;          // return false
        cout << streamChecker->query('i') << " false" << endl;          // return false
        cout << streamChecker->query('j') << " false" << endl;          // return false
        cout << streamChecker->query('k') << " false" << endl;          // return false
        cout << streamChecker->query('l') << " false" << endl;
    }
};