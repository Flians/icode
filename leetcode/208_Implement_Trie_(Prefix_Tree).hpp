#include "../base/icode.hpp"
struct TrieNode
{
    TrieNode *children[26];
    bool isEnd;
    TrieNode()
    {
        for (auto &item : this->children)
            item = NULL;
        this->isEnd = false;
    }
};

class Trie : public icode
{
public:
    TrieNode *root;
    /** Initialize your data structure here. */
    Trie()
    {
        this->root = new TrieNode();
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        TrieNode *ite = this->root;
        for (auto c : word)
        {
            if (!ite->children[c - 'a'])
            {
                ite->children[c - 'a'] = new TrieNode();
            }
            ite = ite->children[c - 'a'];
        }
        ite->isEnd = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        TrieNode *ite = this->root;
        for (auto c : word)
        {
            if (ite->children[c - 'a'])
            {
                ite = ite->children[c - 'a'];
            }
            else
            {
                return false;
            }
        }
        return ite->isEnd;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        TrieNode *ite = this->root;
        for (auto c : prefix)
        {
            if (ite->children[c - 'a'])
            {
                ite = ite->children[c - 'a'];
            }
            else
            {
                return false;
            }
        }
        return true;
    }

    void run()
    {
        /*
        ["Trie","insert","search","search","startsWith","insert","search"]
        [[],["apple"],["apple"],["app"],["app"],["app"],["app"]]
        */
        Trie *obj = new Trie();
        obj->insert("apple");
        cout << "insert 'apple'" << endl;
        cout << "search 'apple' " << obj->search("apple") << endl;
        cout << "search 'app' " << obj->search("app") << endl;
        cout << "startsWith 'app' " << obj->startsWith("app") << endl;
        obj->insert("app");
        cout << "insert 'app'" << endl;
        cout << "search 'app' " << obj->search("app") << endl;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */