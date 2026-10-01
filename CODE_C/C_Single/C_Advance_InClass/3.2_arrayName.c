#include <stdio.h>

void f(int arr[], int n) // 数组名作为函数的参数（首地址）
{
}

void f2(int *x, int n); // 实参的首地址传给形参（指针变量），函数用指针访问实参

int main()
{
    int array[10];
    f(array, 10); // 实参用单独指针变量，需要对指针变量初始化

    return 0;
}