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