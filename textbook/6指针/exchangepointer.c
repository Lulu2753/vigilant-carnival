#include <stdio.h>

int main()
{
	char a[100], b[100], * p = a, * q = b, * t;
	int m;

	gets(p); gets(q);  //以换行为结束
	m=(t = p, p = q, q = t); //逗号表达式返回的是最后一个的地址值(a)，但是赋值的过程一经写出就发生，用==这些才返回真值【逻辑表达式！】
	puts(p); puts(q);
	printf("%d\n", m);  //这就会返回地址值


	//用指针交换就不需要strcpy！因为交换地址值

	return 0;
}