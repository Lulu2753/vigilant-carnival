#include <stdio.h>

int main()
{
	int m;
	float x;
	scanf_s("%d%f", &m, &x);//不能将float值赋给int，只能反过来，否则显示0

	
	printf("\nm=%d\tx=%6.2f", m, x);
	/*
	%6.2f表示占6位，小数点为1位，小数点后2位，小数点前3位，不足3位就补空格
	\t表示tab
	*/
	int p;
	scanf_s("%2d", &p);  //表示输入两位就截至
	printf("%-6d,(0)%o,(0x)%x", p,p, p); //前者转换为八进制，后者转换为十六进制，long型则改为lo或lx,-表示在域内左对齐，占6位空


	double y=0.0039;
	printf("\n%.2e", y);//输出形式：3.90e-03，默认6位小数

}