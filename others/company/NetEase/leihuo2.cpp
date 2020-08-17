#include "iostream"
using namespace std;
// 定义初始化/列表初始化 -> 构造函数
// 按照声明顺序，先基类静态成员，再是子类静态成员，再是基类普通成员，最后是子类普通成员，且父类构造函数先于子类构造函数
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
