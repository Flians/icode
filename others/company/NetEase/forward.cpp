#include <utility>
#include <iostream>

void bar(const int &x)
{
    std::cout << "lvalue" << std::endl;
}

void bar(int &&x)
{
    std::cout << "rvalue" << std::endl;
}

template <typename T>
void foo(T &&x)
{
    bar(x);
    bar(std::forward<T>(x));
}

int main()
{
    int x = 10;
    foo(x);  // lvalue lvalue
    foo(10); // lvalue rvalue

    int i = 10;
    bar(std::forward<int>(i)); // rvalue
    bar(std::forward<int &>(i)); // lvalue
    bar(std::forward<int &&>(i)); // rvalue

    foo(i); // lvalue lvalue
    foo(std::move(i)); // lvalue rvalue
    return 0;
}