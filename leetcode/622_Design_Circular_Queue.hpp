#include "../base/icode.hpp"
class MyCircularQueue : public icode
{
private:
    std::size_t len;
    std::vector<int> values;

public:
    MyCircularQueue()
    {
        this->len = 16;
        this->values.reserve(16);
    }

    MyCircularQueue(int k)
    {
        this->len = k;
        this->values.reserve(k);
    }

    bool enQueue(int value)
    {
        if (this->values.size() >= this->len)
            return false;
        this->values.push_back(value);
        return true;
    }

    bool deQueue()
    {
        if (this->values.empty())
            return false;
        this->values.erase(this->values.begin());
        return true;
    }

    int Front()
    {
        if (this->values.empty())
            return -1;
        return this->values.front();
    }

    int Rear()
    {
        if (this->values.empty())
            return -1;
        return this->values.back();
    }

    bool isEmpty()
    {
        return this->values.empty();
    }

    bool isFull()
    {
        return this->values.size() == this->len;
    }

    void run()
    {
        MyCircularQueue *obj = new MyCircularQueue(6);
        std::cout << obj->enQueue(6) << " true" << std::endl;
        std::cout << obj->deQueue() << " true" << std::endl;
        std::cout << obj->Front() << " -1" << std::endl;
        std::cout << obj->enQueue(5) << " true" << std::endl;
        std::cout << obj->Rear() << " 5" << std::endl;
        std::cout << obj->isEmpty() << " false" << std::endl;
        std::cout << obj->isFull() << " false" << std::endl;
        delete obj;
    }
};