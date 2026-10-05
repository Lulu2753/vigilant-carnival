#include <stdio.h>

struct A
{
    int x;
} a1;

typedef struct B
{
    int y;
} B; // 末尾的名称就是类型的别名，前面的B是struct的名称

struct C
{
    int z;
};

typedef struct
{
    int w;
} D; // 匿名结构体，D为他的类型别名，用这个类型别名即可指代这个结构体

int main()
{
    struct A a2;
    B b1;
    struct B b2;
    struct C c1;
    D d1;

    /*A a3;
     C c2;
     struct D d2;
     以上报错*/
}