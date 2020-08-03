#include "../base/icode.hpp"
class MyHashSet : public icode {
public:
    /** Initialize your data structure here. */
    vector<vector<int> > data;
    int length;
    
    MyHashSet() {
        this->length = 10;
        this->data.resize(this->length);
    }
    
    void add(int key) {
        int index = key%this->length;
        int val = key/this->length;
        bool flag = true;
        for (size_t i=0; i < this->data[index].size(); ++i) {
            if (this->data[index][i] > val) {
                flag = false;
                this->data[index].insert(this->data[index].begin() + i, val);
                break;
            } else if (this->data[index][i] == val) {
                flag = false;
                break;
            }
        }
        if (flag) {
            this->data[index].emplace_back(val);
        }
    }
    
    void remove(int key) {
        int index = key%this->length;
        int val = key/this->length;
        for (size_t i=0; i < this->data[index].size(); ++i) {
            if (this->data[index][i] > val) {
                break;
            } else if (this->data[index][i] == val) {
                this->data[index].erase(this->data[index].begin() + i);
                break;
            }
        }
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int index = key%this->length;
        int val = key/this->length;
        for (size_t i=0; i < this->data[index].size(); ++i) {
            if (this->data[index][i] > val) {
                break;
            } else if (this->data[index][i] == val) {
                return true;
            }
        }
        return false;
    }

    void run()
    {
        MyHashSet hashSet;
        hashSet.add(1);         
        hashSet.add(2);         
        hashSet.contains(1);    // returns true
        hashSet.contains(3);    // returns false (not found)
        hashSet.add(2);          
        hashSet.contains(2);    // returns true
        hashSet.remove(2);          
        hashSet.contains(2);    // returns false (already removed)
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */