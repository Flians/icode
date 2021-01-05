#include <iostream>
#include <functional>
#include <map>
using namespace std;

// c type global function
int c_func(int a, int b)
{
    return a + b;
}

struct divide
{
    int operator()(int denominator, int divisor)
    {
        return denominator / divisor;
    }
};

// function object
struct functor
{
public:
    int operator()(int a, int b)
    {
        return a + b;
    }
};

// template function object
template <class T>
struct template_functor
{
public:
    T operator()(T a, T b)
    {
        return a + b;
    }
};

class Plus
{
public:
    int num;

public:
    Plus() {}
    Plus(int num_) : num(num_) {}

    static int plus(int a, int b)
    {
        return a + b;
    }

    int plus_(int a, int b)
    {
        return a + b;
    }
};

int main()
{
    // C
    typedef int (*Func)(int, int);
    Func C_func = c_func;
    cout << C_func(1, 2) << endl; //3

    // C++98
    functor ft;
    cout << ft(1, 2) << endl; //3

    std::function<int(int, int)> fun_func = c_func;
    cout << fun_func(1, 2) << endl;

    std::function<int(int, int)> fun_obj = functor();
    cout << fun_obj(1, 2) << endl; //3
    fun_obj = ft;
    cout << fun_obj(1, 2) << endl; //3

    function<int(int, int)> fun_tmp = template_functor<int>();
    cout << fun_tmp(1, 2) << endl; //3

    auto lamd = [](const int a, const int b) { return a + b; };
    std::function<int(int, int)> fun_lamd = lamd;
    cout << fun_lamd(1, 2) << endl; // 3

    function<int(int, int)> fun_static = &Plus::plus;
    cout << fun_static(1, 2) << endl; //3

    Plus p(2);
    function<int(Plus &, int, int)> fun_member = &Plus::plus_;
    cout << fun_member(p, 1, 2) << endl; //3
    function<int(const Plus, int, int)> fun_member2 = &Plus::plus_;
    cout << fun_member2(p, 1, 2) << endl; //3

    function<int(Plus &)> fun_att = &Plus::num;
    cout << fun_att(p) << endl; //2
    function<int(const Plus)> fun_att2 = &Plus::num;
    cout << fun_att2(p) << endl; //2

    // 指针形式调用成员函数
    function<int(int, int)> fun_bind_point = bind(&Plus::plus_, &p, placeholders::_1, placeholders::_2); // placeholders::_1是占位符
    cout << fun_bind_point(1, 2) << endl;                                                                //3
    // 对象形式调用成员函数
    function<int(int, int)> fun_bind_obj = bind(&Plus::plus_, p, placeholders::_1, placeholders::_2); // placeholders::_1是占位符
    cout << fun_bind_obj(1, 2) << endl;                                                               //3

    map<char, function<int(int, int)>> binops = {
        {'+', c_func},
        {'-', [](int i, int j) { return i - j; }},
        {'/', divide()}};
    cout << binops['+'](10, 5) << endl;
    cout << binops['-'](10, 5) << endl;
    cout << binops['/'](10, 5) << endl;
    return 0;
}
