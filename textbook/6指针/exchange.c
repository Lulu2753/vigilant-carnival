#include <stdio.h>

void Swap(int *x, int *y);

int main()
{
	int a, b;
	a = 5;
	b = 9;
	Swap(&a, &b);  //括号里面是地址，指针作为函数参数
	printf("a = % d, b = % d",a,b);

	return 0;
}


void Swap(int *x, int *y)   //不加指针只是传来的两个数暂时交换位置，没有传回去，指针为桥梁，除非在这个里面print
{
	int temp;  //这里不能设为指针，因为不知道指向哪里，指针必须伴随指向的地方
	temp = *x;
	*x = *y;
	*y = temp;
}