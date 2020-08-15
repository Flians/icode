#include <stdio.h>
#include <utility>
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
    B b;
    B m(b);
    B n = b;
    B q(std::move(b));
    return 0;
}