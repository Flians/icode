#include "../base/icode.hpp"
class RandomizedSet : public icode {
public:
    unordered_set<int> data;
    /** Initialize your data structure here. */
    RandomizedSet() {
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        return data.insert(val).second;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(data.erase(val))
            return 1;
        return 0;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return *next(data.begin(), rand() %data.size());
    }

    void run() {
        RandomizedSet* obj = new RandomizedSet();
        cout << obj->insert(1) << " 1" << endl;
        cout << obj->remove(2) << " 0" << endl;
        cout << obj->insert(2) << " 1" << endl;
        cout << obj->getRandom() << " 1" << endl;
        cout << obj->remove(1) << " 1" << endl;
        cout << obj->insert(2) << " 0" << endl;
        cout << obj->getRandom() << " 2" << endl;
    }
};
