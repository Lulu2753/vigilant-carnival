#include <stdio.h>

int main()
{
    int *p, *q, r = 0, s = 1;
    q = &s;                          // q是s的地址，*q=s=1
    p = &r;                          // p是r的地址，*p=r=0
    *q = r;                          // r的值赋给q代表的内容，*q=r=0
    printf("*p=%d,*q=%d\n", *p, *q); //*p=0, *q=0
    r++;                             // r=1，*p=r=1
    printf("*p=%d,*q=%d", *p, *q);   //*p=1, *q=0
    return 0;
}
