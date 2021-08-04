#include "../base/icode.hpp"
class MapSum : public icode {
private:
    struct MapNode {
        MapNode* children[26];
        int sum;
        MapNode() {
            fill_n(this->children, 26, (MapNode*)NULL);
            this->sum = 0;
        }
    };
    MapNode* root;
    unordered_map<string, int> strs;
public:
    /** Initialize your data structure here. */
    MapSum() {
        root = new MapNode();
    }
    
    void insert(string key, int val) {
        MapNode* cur = root;
        int recovey = val;
        if (strs.find(key) != strs.end()) {
            val -= strs[key];
        }
        strs[key] = recovey;
        for (int i = 0, n = key.size(); i < n; ++i) {
            int index = key[i] - 'a';
            if (!cur->children[index]) {
                cur->children[index] = new MapNode();
            }
            cur = cur->children[index];
            cur->sum += val;
        }
    }
    
    int sum(string prefix) {
        MapNode* cur = root;
        for (int i = 0, n = prefix.size(); i < n; ++i) {
            int index = prefix[i] - 'a';
            if (!cur->children[index]) {
                return 0;
            }
            cur = cur->children[index];
        }
        return cur->sum;
    }
    
    void run() {
        MapSum* obj = new MapSum();
        obj->insert("apple",2);
        cout << obj->sum("app") << " 2\n";
        delete obj;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */