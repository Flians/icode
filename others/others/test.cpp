#include <stdio.h>
#include <string.h>
#include <malloc.h>

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

int main()
{
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
    return 0;
}