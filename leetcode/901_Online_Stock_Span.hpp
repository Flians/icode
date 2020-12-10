#include "../base/icode.hpp"
class StockSpanner : public icode
{
private:
    stack<pair<int, int>> stock;
public:
    StockSpanner(){}
    virtual ~StockSpanner(){}
    int next(int price)
    {
        int span = 1;
        while (!stock.empty() && stock.top().first <= price)
        {
            span += stock.top().second;
            stock.pop();
        }
        stock.push(make_pair(price, span));
        return span;
    }

    void run()
    {
        /*
        [100, 80, 60, 70, 60, 75, 85]
        [1, 1, 1, 2, 1, 4, 6]
        */
        StockSpanner *obj = new StockSpanner();
        cout << obj->next(100) << endl;
        cout << obj->next(80) << endl;
        cout << obj->next(60) << endl;
        cout << obj->next(70) << endl;
        cout << obj->next(60) << endl;
        cout << obj->next(75) << endl;
        cout << obj->next(85) << endl;
        delete obj;
    }
};