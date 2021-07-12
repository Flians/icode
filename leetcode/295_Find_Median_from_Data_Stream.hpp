#include "../base/icode.hpp"
class MedianFinder : public icode
{
private:
    priority_queue<int> maxh;
    priority_queue<int, vector<int>, greater<int>> minh;

public:
    /** initialize your data structure here. */
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        maxh.push(num);
        minh.push(maxh.top());
        maxh.pop();
        if (minh.size() > maxh.size())
        {
            maxh.push(minh.top());
            minh.pop();
        }
    }

    double findMedian()
    {
        if (maxh.size() == minh.size())
            return (maxh.top() + minh.top()) / 2.0;
        return maxh.top();
    }

    void run()
    {
        MedianFinder *obj = new MedianFinder();
        obj->addNum(1);
        obj->addNum(2);
        obj->addNum(3);
        cout << obj->findMedian() << " 2" << endl;
    }
};