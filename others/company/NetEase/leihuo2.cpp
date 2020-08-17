#include "iostream"
using namespace std;
// const成员变量必须在定义初始化/初始化列表中指定初值
// static成员变量的内存既不是在声明类时分配，也不是在创建对象时分配，而是在类外初始化时分配。先初始化static，在声明类对象
// 定义初始化/列表初始化 -> 构造函数。定义初始化等同于列表初始化，若有列表初始化，则不进行定义初始化
// 按照声明顺序，先基类静态成员，再是子类静态成员，再是基类普通成员，最后是子类普通成员，且父类构造函数先于子类构造函数
class A
{
public:
    int a1 = 10;
    int a2 = 20;
    static int a3;
    const int a4 = 40;
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
