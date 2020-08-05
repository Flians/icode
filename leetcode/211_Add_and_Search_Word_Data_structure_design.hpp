#include "../base/icode.hpp"
class WordDictionary : public icode {
public:
    struct TrieNode {
        TrieNode* children[26];
        bool is_end;
        TrieNode() {
            this->is_end = false;
            for (auto &item : children) {
                item = NULL;
            }
        }
    };
    
    TrieNode* root;
    /** Initialize your data structure here. */
    WordDictionary() {
        this->root = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode* tmp = this->root;
        for (auto &c : word) {
            if (!tmp->children[c-'a']) {
                tmp->children[c-'a'] = new TrieNode();
            }
            tmp = tmp->children[c-'a'];
        }
        tmp->is_end = true;
    }
    
    bool search(int i, string word, TrieNode* root) {
        TrieNode* tmp = root;
        while (i < (int)word.length()) {
            if (word[i] == '.') {
                bool flag = false;
                for (auto &item : tmp->children) {
                    if (item && search(i+1, word, item)) {
                        flag = true;
                        break;
                    }
                }
                return flag;
            } else {
                if (!tmp->children[word[i]-'a']) {
                    return false;
                }
                tmp = tmp->children[word[i++]-'a'];
            }
        }
        return tmp->is_end;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return search(0, word, this->root);
    }

    void run() {
        WordDictionary wd;
        wd.addWord("bad");
        wd.addWord("dad");
        wd.addWord("mad");
        cout << wd.search("pad") << " -> false" << endl;
        cout << wd.search("bad") << " -> true" << endl;
        cout << wd.search(".ad") << " -> true" << endl;
        cout << wd.search("b..") << " -> true" << endl;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */