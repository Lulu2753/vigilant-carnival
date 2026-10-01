#include <stdio.h>

int func(int x)
{
    return x * 2;
}

int main()
{
    int arr[2] = {100, 200};
    int (*fp)(int) = func; // 定义函数指针fp，指针指向函数，括号里的int表示指向的函数接收int参数
    // fp指向func这个函数！！
    // 如果变成int *p()，没有括号，会解读为函数名为p，返回值为整型指针变量
    int (*ap)[2] = &arr; // 数组指针，指向arr，(*ap)表示指向数组的指针，[2]表示包含两个元素
    // arr表示整个数组的地址
    printf("%d %d", fp(5), (*ap)[1]);
    // 调用：c=(*p)(a);  // 先解引用，再调用函数

    return 0;
}