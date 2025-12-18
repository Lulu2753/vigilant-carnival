#include <stdio.h>

int main()
{
	int a=12, b=18, * pa, * pb;   //只能同类型赋值

	pa = &a;
	pb = &b;    //指针就是地址，*就是取内容

	printf("%d %d\n", a, b);
	printf("%d %d\n", *pa, *pb);

	return 0;
}