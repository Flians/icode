#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <iostream>
#include <memory>

using namespace std;

void fun (shared_ptr<int> p) {
    *p=5;
}

void Func(char str[100])
{
    printf("%d\n", sizeof(str));
}

void getM(char *p)
{
    p = (char *)malloc(100);
}

char *getM(void)
{
    char p[] = "hello world";
    return p;
}

void getM(char **p, int num)
{
    *p = (char *)malloc(num);
}

void Test1(void)
{
    char *str = NULL;
    getM(str);
    strcpy(str, "hello world");
    printf("%s\n", str);
}

void Test2(void)
{
    char *str = NULL;
    str = getM();
    printf("%s\n", str);
}

void Test3(void)
{
    char *str = NULL;
    getM(&str, 100);
    strcpy(str, "hello world");
    printf("%s\n", str);
}

void Test4(void)
{
    char *str = (char *)malloc(100);
    strcpy(str, "hello");
    free(str);
    if (str != NULL)
    {
        strcpy(str, "world");
        printf("%s\n", str);
    }
}

void Test5(void)
{
    char str[] = "Hell0o";
    printf("%d\n", sizeof(str));
    Func(str);
    char *p = str;
    printf("%d\n", sizeof(p));
    int nn = 10;
    printf("%d\n", sizeof(nn));
    void *pm = malloc(100);
    printf("%d\n", sizeof(pm));
}
class test
{
private:
    int x;
public:
    void set(int x_){
        this->x = x_;
    }
    int get(){
        return x;
    }
};

void fun(test *a) {
    a[0].set(1);
}

int main()
{
    /*
    char a;
    printf("%c\n", a);
    char *str = &a;
    strcpy(str, "h");
    printf("%s\n", str);
    printf("%c\n", str);
    printf(" ---------- \n");
    // Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    */
   /*
   int a= 6;
   for (int i =0; i < 100; i++) {
       shared_ptr<int> p = make_shared<int>(a);
       fun(p);
       cout << *p;
   }
   */
  test a[2];
  a[0].set(2);
  fun(a);
  cout << a[0].get() << endl;
    return 0;
}