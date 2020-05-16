#include "../base/icode.hpp"

class LRUCache : public icode
{
public:
    struct Node
    {
        int key;
        int val;
        Node *pre;
        Node *next;
        Node(int k, int v) : key(k), val(v), pre(NULL), next(NULL) {}
    };

    int size;
    Node *head;
    Node *tail;
    map<int, Node *> tab;
    LRUCache()
    {
        this->size = 0;
        this->head = NULL;
        this->tail = NULL;
    }

    LRUCache(int capacity)
    {
        this->head = NULL;
        this->tail = NULL;
        this->size = capacity;
    }

    int get(int key)
    {
        if (this->tab.empty() || this->tab.count(key) == 0)
            return -1;
        if (key != this->head->key)
        {
            if (this->tab[key]->next)
            {
                this->tab[key]->pre->next = this->tab[key]->next;
                this->tab[key]->next->pre = this->tab[key]->pre;
            }

            this->tab[key]->next = this->head;
            this->head->pre = this->tab[key];
            this->tab[key]->pre = NULL;
            this->head = this->tab[key];
        }
        return this->head->val;
    }

    void put(int key, int value)
    {
        if (this->tab.count(key))
        {
            get(key);
            this->head->val = value;
        }
        else
        {
            if (this->size == (int) this->tab.size())
            {
                this->tab.erase(this->tail->pre->key);
                this->tail->pre->key = key;
                this->tail->pre->val = value;
                this->tail->pre->next = this->head;
                this->head->pre = this->tail->pre;
                this->head = this->tail->pre;
                this->tail->pre->pre->next = this->tail;
                this->tail->pre = this->tail->pre->pre;
                this->head->pre = NULL;
            }
            else
            {
                if (this->head)
                {
                    Node *nh = new Node(key, value);
                    nh->next = this->head;
                    this->head->pre = nh;
                    this->head = nh;
                }
                else
                {
                    this->head = new Node(key, value);
                    this->tail = new Node(-1, -1);
                    this->head->next = this->tail;
                    this->tail->pre = this->head;
                }
            }
            tab[key] = this->head;
        }
    }

    void run()
    {
        LRUCache cache(2 /* capacity */);
        cache.put(1, 1);
        cache.put(2, 2);
        cout << cache.get(1) << " ";  // returns 1
        cache.put(3, 3);              // evicts key 2
        cout << cache.get(2);         // returns -1 (not found)
        cache.put(4, 4);              // evicts key 1
        cout << cache.get(1) << " ";  // returns -1 (not found)
        cout << cache.get(3) << " ";  // returns 3
        cout << cache.get(4) << endl; // returns 4
    }
};