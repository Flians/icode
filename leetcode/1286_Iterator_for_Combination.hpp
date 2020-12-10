#include "../base/icode.hpp"
class CombinationIterator : public icode {
private:
    size_t index;
    vector<string> all;
public:
    CombinationIterator() {}
    virtual ~CombinationIterator() {}
    CombinationIterator(string characters, int combinationLength) {
        this->index = 0;
        if ((int)characters.length() >= combinationLength) {
            backtrack(characters, combinationLength, 0, "");
        }
    }
    
    void backtrack(string &characters, int combinationLength, int index, string cur) {
        if ((int)cur.length() == combinationLength) {
            all.emplace_back(cur);
            return;
        }
        for (size_t i = index; i < characters.length(); ++i) {
            backtrack(characters, combinationLength, i + 1, cur + characters[i]);
        }   
    }
    
    string next() {
        return hasNext() ? all[index++] : "";
    }
    
    bool hasNext() {
        return index < all.size();
    }

    void run() {
        CombinationIterator* obj = new CombinationIterator("abc", 2);
        cout << obj->next() << " ab" << endl;
        cout << obj->hasNext() << " 1" << endl;
        cout << obj->next() << " ac" << endl;
        cout << obj->hasNext() << " 1" << endl;
        cout << obj->next() << " bc" << endl;
        cout << obj->hasNext() << " 0" << endl;
        delete obj;
    }
};