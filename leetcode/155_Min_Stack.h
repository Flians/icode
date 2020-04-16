#include "../base/icode.h"

class MinStack : public icode
{
public:
    stack<int> data;
    stack<int> min_data;
    int minx;
    /** initialize your data structure here. */
    MinStack()
    {
        minx = 0;
    }

    void push(int x)
    {
        if (min_data.size() > 0)
            minx = min(minx, x);
        else
            minx = x;
        data.push(x);
        min_data.push(minx);
    }

    void pop()
    {
        if (data.empty())
            throw "overflowed!";
        data.pop();
        min_data.pop();
        if (!min_data.empty())
            minx = min_data.top();
    }

    int top()
    {
        if (data.empty())
            throw "overflowed!";
        return data.top();
    }

    int getMin()
    {
        return minx;
    }

    void run()
    {
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */