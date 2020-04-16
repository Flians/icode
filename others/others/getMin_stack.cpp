/**
 * override the stack to get the minimum of the stack
 * the solution: use a auxiliary stack to record the index of the minimum element for each element in stack.
 */
#include <iostream>
#include <stack>
using namespace std;

template<class T> struct node
{
    T data;
    node *next;
};

template<class T> class MinStack
{
public:
    MinStack();
    ~MinStack();
    void push(T data);
    void pop();
    T top();
    bool isEmpty();
    int size();
    T get(int index);
    T getMin();
private:
    node<T> *node_top;
    // Auxiliary stack used to record the position of minimum element.
    node<int> *data_top;
};

template<class T> MinStack<T>::MinStack()
{
    node_top = NULL;
    data_top = NULL;
}

template<class T> MinStack<T>::~MinStack()
{
    node<T> *node = NULL;
    while(node_top != NULL)
    {
        node = node_top;
        node_top = node_top->next;
        delete node;
    }
    node = NULL;
    while(data_top != NULL)
    {
        node = data_top;
        data_top = data_top->next;
        delete node;
    }
}

template<class T> void MinStack<T>::push(T data)
{
    node<T> *newn = new node<T>;
    newn->data = data;
    newn->next = node_top;
    node_top = newn;
    newn = NULL;
    // push index 0 into data_top if data_top is empty.
    if(data_top == NULL)
    {
        newn = new node<T>;
        newn->data = 0;
        newn->next = NULL;
        data_top = newn;
    }
    else
    {
        T min_now = getMin();
        // push the max index into data_top if data is less than min_now.
        if(data < min_now)
        {
            newn = new node<T>;
            newn->data = size() - 1;
            newn->next = data_top;
            data_top = newn;
        }
    }
    newn = NULL;
}

template<class T> void MinStack<T>::pop()
{
    if(node_top != NULL)
    {
        node<T> *temp = new node<T>;
        if(size()-1 == data_top->data)
        {
            temp = data_top;
            data_top = data_top->next;
            delete temp;
        }
        temp = node_top;
        node_top = node_top->next;
        delete temp;
    }
    else
        throw "the stack is empty!\n";
}

template<class T> T MinStack<T>::top()
{
    if(node_top != NULL)
        return node_top->data;
    else
        throw "the stack is empty!\n";
}

template<class T> bool MinStack<T>::isEmpty()
{
    return node_top == NULL;
}

template<class T> int MinStack<T>::size()
{
    int size = 0;
    node<T> *temp = node_top;
    while(temp!=NULL)
    {
        size++;
        temp = temp->next;
    }
    return size;
}

template<class T> T MinStack<T>::get(int index)
{
    int len = size()-1;
    node<T> *temp = node_top;
    while(temp!=NULL)
    {
        if(index == len)
        {
            return temp->data;
        }
        len--;
        temp = temp->next;
    }
    throw "the parameter 'index' is out of range!\n";
}

template<class T> T MinStack<T>::getMin()
{
    if(node_top != NULL)
        return get(data_top->data);
    else
        throw "the stack is empty!\n";
}

int main()
{
    MinStack<int> stack;
    stack.push(7);
    stack.push(6);
    stack.push(5);
    stack.push(4);
    stack.push(3);
    stack.push(2);
    stack.push(1);
    int size = stack.size();
    for(int i = 0; i < size; i++)
    {
        cout << stack.get(i) << " ";
    }
    cout << endl;
    stack.pop();
    cout <<"size:" << stack.size() << ", top:" << stack.top() << ", min:" << stack.getMin() << endl;
    return 0;
}
