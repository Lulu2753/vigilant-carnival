#include <stdio.h>

int power(int, int);   //表示这里是两个整数，参数名可以不加（m,n)，默认情况下返回int，若省略int也可以默认返回int

int main()
{
    int i;

    for(i = 0; i < 10; ++i)
        printf("%d\t%d\t%d\n", i, power(2,i), power(-3,i));    //函数不直接修改主调函数变量的值，自己作为一个值，自己内部值改变，i传递到函数自己的n等，只能通过指针修改主调函数的变量

    return 0;     //表示正常终止，调用者：程序执行环境
}

int power(int base, int n)  //函数内部用到的参数，其他函数不能用，无关
{
    int i, p;

    p = 1;
    for(i = 1; i <= n; ++i)
        p = p * base;
    return p;      //无return则结束时将控制权还给主调函数，函数里面的return要打星号
}