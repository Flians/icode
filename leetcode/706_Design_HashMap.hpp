#include "../base/icode.hpp"

class MyHashMap : public icode
{
private:
    std::vector<HashNode *> items;

public:
    /** Initialize your data structure here. */
    MyHashMap()
    {
        items.resize(10001, nullptr);
    }

    int hash(int key)
    {
        return ((key % 10001) * (key % 10001)) % 10001;
    }

    /** value will always be non-negative. */
    void put(int key, int value)
    {
        int _key = hash(key);
        HashNode *newn = new HashNode(key, value, items[_key]);
        /*
        HashNode* node = this->items[_key];
        if (node) {
            while (node) {
                if (node->key == key) {
                    node->val = value;
                    delete newn;
                    return;
                }
                if (node->next == nullptr) {
                    node->next = newn;
                    return;
                }
                node = node->next;
            }
        } else {
            this->items[_key] = newn;
        }
        */

        items[_key] = newn;
        while (newn && newn->next)
        {
            auto tmp = newn->next;
            if (tmp->key == key)
            {
                newn->next = tmp->next;
                delete tmp;
            }
            newn = newn->next;
        }
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key)
    {
        int _key = hash(key);
        HashNode *tmp = items[_key];
        while (tmp)
        {
            if (tmp->key == key)
            {
                return tmp->val;
            }
            tmp = tmp->next;
        }
        return -1;
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key)
    {
        int _key = hash(key);
        HashNode *tmp = items[_key], *last = nullptr;
        while (tmp)
        {
            if (tmp->key == key)
            {
                if (last)
                {
                    last->next = tmp->next;
                }
                else
                {
                    items[_key] = tmp->next;
                }
                delete tmp;
                break;
            }
            last = tmp;
            tmp = tmp->next;
        }
    }

    void run()
    {
        MyHashMap *obj = new MyHashMap();
        obj->put(1, 1);
        obj->put(2, 2);
        cout << obj->get(1) << " 1" << endl;
        cout << obj->get(3) << " -1" << endl;
        obj->put(2, 1);
        cout << obj->get(2) << " 1" << endl;
        obj->remove(2);
        cout << obj->get(2) << " -1" << endl;
        delete obj;
    }
};