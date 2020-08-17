#include <stdio.h>
#include <utility>

// *操作符是左操作符，左操作符的优先级是从右到左
// const int *p与int const *p等同，指向一个常量，不能通过指针来修改这个指针指向的值。但是p可以修改
// const int *p的含义是p是指向常量整形的指针, p不能再重新赋值了，即不能再指向另一个新地址。但是*p可以修改
// int *const p的含义是p是指向int的常量指针

class A
{
public:
    A() {
        printf("a");
    }
    A(const A&) {
        printf("b");
    }
    A(A&&) {
        printf("c");
    }
    A operator = (const A&) {
        printf("d");
    }
};

class B :public A
{
public:
    int cc = 2;
    B() :A() {
        printf("1");
    }
    B(const B& b) :A(b) {
        printf("2");
    }
    B(B&& b) :A(b) {
        printf("3");
    }
    B operator = (const B&) {
        printf("4");
    }
};


int main()
{
    B b; // a1
    printf("\n");
    B m(b); // b2
    printf("\n");
    B n = b; // b2
    printf("\n");
    B q(std::move(b)); // b3
    printf("\n%d\n", b.cc);
    return 0;
}