#include <stdio.h>

product(int* p1, int* p2)
{
	printf("*p1=%d,*p2=%d\n", *p1, *p2);
	scanf_s("%d%d", p1, p2);  //地址值，相当于给a，b重新赋值，指针使其可以传回去
	printf("*p1=%d,*p2=%d\n", *p1, *p2);
	return *p1 * *p2;
}

int main()
{
	int a, b, c;
	int* pointer_1, * pointer_2;
	scanf_s("%d,%d", &a, &b);  //输入的时候必须输入逗号，否则读入的是随机值
	pointer_1 = &a;
	pointer_2 = &b;
	c = product(pointer_1, pointer_2);
	printf("\na=%d,b=%d,product=%d\n", a, b, c);
	return 0;
}
