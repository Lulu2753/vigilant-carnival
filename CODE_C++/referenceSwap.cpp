#include <iostream>
using namespace std;

void Swap1(int *x, int *y) // 指针调用
{
    int t;
    t = *x;
    *x = *y;
    *y = t;
}

void Swap2(int x, int y) // 传值调用
{
    int t;
    t = x;
    x = y;
    y = t;
}

void Swap3(int &x, int &y) // 引用调用【&在这里是定义引用变量！】，用x代替a，y代替b
// 引用的同时会改变被引用的，同时的关系，直接操作被引用的实参，即使后面内存被释放
{
    int t = x;
    x = y;
    y = t;
}

int main()
{
    int a = 5, b = 8;
    printf("a=%d, b=%d\n", a, b);

    Swap1(&a, &b); // 形参是地址，直接指向ab，只是把地址传到函数
    // 回到主函数，形参会被删掉，释放掉，但已经交换地址
    printf("a=%d, b=%d\n", a, b);

    a = 5, b = 8;
    // Swap1已经交换ab，运行后续的需要重置！！

    Swap2(a, b); // 【无法交换】单纯把a的值传给x，b的值传给y，x和y单独分配内存，相当于两个东西
    // ab实参，xy形参，形参是实参的副本，形参和实参不在同一个内存地址
    printf("a=%d, b=%d\n", a, b);

    Swap3(a, b); // 引用调用，直接使用实参的引用，改变实参的值
    printf("a=%d, b=%d\n", a, b);

    system("pause");
    return 0;
}