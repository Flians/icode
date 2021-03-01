#include "../base/icode.hpp"
class FreqStack : public icode
{
private:
    map<int, int> freq;
    map<int, stack<int>> group;
    int maxfreq;

public:
    FreqStack()
    {
        maxfreq = 0;
    }

    virtual ~FreqStack() = default;

    void push(int x)
    {
        auto _find = freq.find(x);
        if (_find == freq.end())
        {
            freq[x] = 1;
        }
        else
        {
            ++freq[x];
        }
        int f = freq[x];
        if (f > maxfreq)
            maxfreq = f;
        auto _gfind = group.find(f);
        if (_gfind == group.end())
        {
            stack<int> item;
            item.push(x);
            group[f] = item;
        }
        else
        {
            _gfind->second.push(x);
        }
    }

    int pop()
    {
        auto &item = group[maxfreq];
        int x = item.top();
        item.pop();
        --freq[x];
        if (item.size() == 0)
            maxfreq--;
        return x;
    }

    void run()
    {
        /*
        [5,7,5,4]
        */
        FreqStack *obj = new FreqStack();
        obj->push(5);
        obj->push(7);
        obj->push(5);
        obj->push(7);
        obj->push(4);
        obj->push(5);
        cout << obj->pop() << endl;
        cout << obj->pop() << endl;
        cout << obj->pop() << endl;
        cout << obj->pop() << endl;
        delete obj;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */