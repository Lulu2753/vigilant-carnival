#include <stdio.h>

void f(int a[10]) // 传入的数组退化为（一级）指针，只能接受int指针
{                 // a[10]等同于a[]，10此处被忽略，不会检查，取决于写入的a
    a[0] = 100;   // 令传入的数组第一个变成100
    a++;          // 局部指针自增，马上就释放掉内存
}

void g(int *a)
{
    *a = 200; // 传入指针所指向的变成200
    a = NULL;
}

int main(void)
{
    int x = 1;
    int *p = &x;
    int arr[3] = {1, 2, 3};

    f(p);
    f(arr);
    f(&x);
    f(NULL);
    g(p);
    g(arr);

    return 0;
}