/**
 * explicit, 只能用于修饰只有一个参数的类构造函数, 它的作用是表明该构造函数是显示的, 而非隐式的.
 * 如果类构造函数参数大于或等于两个时, 是不会产生隐式转换的, 所以explicit关键字也就无效了
 * 当除了第一个参数以外的其他参数都有默认值的时候, explicit关键字依然有效, 当调用构造函数时只传入一个参数, 等效于只有一个参数的类构造函数
 * implicit, 隐式的,类构造函数默认情况下即声明为implicit(隐式).
 */
#include <malloc.h>
#include <string.h>
#include <iostream>

class CxString // 没有使用explicit关键字的类声明, 即默认为隐式声明
{
public:
    char *_pstr;
    int _age;
    int _size;

    CxString(int size)
    {
        _age = 0;
        _size = size;                                   // string的预设大小
        _pstr = static_cast<char *>(malloc(_size + 1)); // 分配string的内存
        memset(_pstr, 0, size + 1);
    }
    CxString(const char *p)
    {
        int size = strlen(p);
        _pstr = static_cast<char *>(malloc(_size + 1)); // 分配string的内存
        strcpy(_pstr, p);                               // 复制字符串
        _size = strlen(_pstr);
        _age = 0;
    }
    CxString(int age, int size) // explicit关键字在类构造函数参数大于或等于两个时无效
    {
        _age = age;
        _size = size;
        _pstr = static_cast<char *>(malloc(_size + 1)); // 分配string的内存
        memset(_pstr, 0, size + 1);
    }
};

class CxString_1 // 使用关键字explicit的类声明, 显示转换
{
public:
    char *_pstr;
    int _age;
    int _size;
    explicit CxString_1(int size)
    {
        _age = 0;
        _size = size;                                   // string的预设大小
        _pstr = static_cast<char *>(malloc(_size + 1)); // 分配string的内存
        memset(_pstr, 0, size + 1);
    }
    CxString_1(const char *p)
    {
        int size = strlen(p);
        _pstr = static_cast<char *>(malloc(_size + 1)); // 分配string的内存
        strcpy(_pstr, p);                               // 复制字符串
        _size = strlen(_pstr);
        _age = 0;
    }
    explicit CxString_1(int age, int size) // explicit关键字在类构造函数参数大于或等于两个时无效
    {
        _age = age;
        _size = size;
        _pstr = static_cast<char *>(malloc(_size + 1)); // 分配string的内存
        memset(_pstr, 0, size + 1);
    }
};

class CxString_2 // 使用关键字explicit的类声明, 显示转换
{
public:
    char *_pstr;
    int _age;
    int _size;
    CxString_2(const char *p)
    {
        int size = strlen(p);
        _pstr = static_cast<char *>(malloc(_size + 1)); // 分配string的内存
        strcpy(_pstr, p);                               // 复制字符串
        _size = strlen(_pstr);
        _age = 0;
    }
    explicit CxString_2(int age, int size = 0)
    {
        _age = age;
        _size = size;
        _pstr = static_cast<char *>(malloc(_size + 1)); // 分配string的内存
        memset(_pstr, 0, size + 1);
    }
};

int main()
{
    CxString string1(24);  // 这样是OK的, 为CxString预分配24字节的大小的内存
    CxString string2 = 10; // 这样是OK的, 为CxString预分配10字节的大小的内存, 在C++中, 如果的构造函数只有一个参数时, 那么在编译的时候就会有一个缺省的转换操作:将该构造函数对应数据类型的数据转换为该类对象, CxString string2(10);.
    // CxString string3;        // 这样是不行的, 因为没有默认构造函数, 错误为: “CxString”: 没有合适的默认构造函数可用
    CxString string3 = string1;  // 这样也是OK的, 至少编译是没问题的, 但是如果析构函数里用free释放_pstr内存指针的时候可能会报错, 完整的代码必须重载运算符"=", 并在其中处理内存释放
    CxString string4("aaaa");    // 这样是OK的
    CxString string5 = "bbb";    // 这样也是OK的, 调用的是CxString(const char *p)
    CxString string6 = 'c';      // 这样也是OK的, 其实调用的是CxString(int size), 且size等于'c'的ascii码
    CxString string7 = {24, 25}; // 这样是OK的
    string1 = 2;                 // 这样也是OK的, 为CxString预分配2字节的大小的内存
    string2 = 3;                 // 这样也是OK的, 为CxString预分配3字节的大小的内存

    CxString_1 string_1(24); // 这样是OK的
    // CxString_1 string_2 = 10;    // 这样是不行的, 因为explicit关键字取消了隐式转换
    // CxString_1 string_3;         // 这样是不行的, 因为没有默认构造函数
    CxString_1 string_3 = string_1; // 这样是OK的
    CxString_1 string_4("aaaa");    // 这样是OK的
    CxString_1 string_5 = "bbb";    // 这样也是OK的, 调用的是CxString(const char *p)
    // CxString_1 string_6 = 'c';        // 这样是不行的, 其实调用的是CxString(int size), 且size等于'c'的ascii码, 但explicit关键字取消了隐式转换
    // CxString_1 string_7 = {24, 25};   // 这样是不行的
    // string_1 = 2;                     // 这样也是不行的, 因为取消了隐式转换

    CxString_2 string__1(24); // 这样是OK的
    // CxString_2 string__2 = 10;     // 这样是不行的, 因为explicit关键字取消了隐式转换
    // CxString_2 string__3;          // 这样是不行的, 因为没有默认构造函数
    CxString_2 string__3 = string__1; // 这样是OK的
    std::cout << string__3._age << std::endl;
    // CxString_2 string__4 = {24, 25};   // 这样是不行的
    // string__1 = 2;                 // 这样也是不行的, 因为取消了隐式转换

    return 0;
}