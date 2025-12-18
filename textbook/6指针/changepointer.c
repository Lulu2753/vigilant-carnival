#include <stdio.h>

int main()
{
	int a, b, * p1, * p2, *p;   //P用来交换指针
	p1 = &a; p2 = &b;  //只能把地址赋给指针，不能直接赋值

	scanf_s("%d%d", &a, &b);

	if (a < b)
	{
		p = p1;
		p1 = p2;
		p2 = p;    //交换地址而非内容
	}

	printf("a=%d b=%d\n", a, b);
	printf("max=%d min=%d\n", *p1, *p2);

	return 0;


}