#include <stdio.h>

void swap(int *px, int *py)
{
    int temp; // 也可以写*temp，但是temp要先赋值，例如temp=&x，要事先赋地址值
    temp = *px;
    *px = *py;
    *py = temp;
}

void swap2(int *px, int *py)
{
    int *p;
    p = px; // 将px这个地址值赋给p，p=px这个地址，即a的地址，没涉及到值本身
    px = py;
    py = p;
    // 以上为地址的传递，但没能改变ab的值，因为只是改变px，py的指向，a，b本身没变
    // 仅交换指向，没操作到ab的值本身，全程都是地址交换而已，单纯形参交换地址值
}

void main()
{
    int a, b, *p1, *p2;
    printf("\nInput a,b:");
    scanf("%d%d", &a, &b);

    p1 = &a;
    p2 = &b;

    swap(p1, p2); // 也可以填&a,&b
    printf("a=%d, b=%d\n", a, b);

    swap2(p1, p2);
    printf("a=%d, b=%d\n", a, b);
}