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
        bool param_2 = obj->search("apple");
        bool param_3 = obj->search("app");
        bool param_4 = obj->startsWith("app");
        obj->insert("app");
        bool param_6 = obj->search("app");
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */