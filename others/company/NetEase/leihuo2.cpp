#include "iostream"
using namespace std;

class A
{
public:
    int a1 = 10;
    int a2 = 20;
    static int a3;
    A() :a2(a3 + 1), a1(a2 + 1) {}
};
int A::a3 = 30;

A a;

int main() {

    cout << a.a1 << endl;
    cout << a.a2 << endl;
    cout << a.a3 << endl;

    getchar();
    return 0;
}
