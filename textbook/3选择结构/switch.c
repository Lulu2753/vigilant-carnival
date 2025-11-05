#include <stdio.h>

int main()
{
	char grade;
	scanf_s("%c", &grade);

	switch (grade)
	{
	case 'A': printf("85~100"); break;  //case内部的只能是单个的int或char，不能是不等式之类，否则报错
	case 'B': printf("70~84"); break;
	case 'C':printf("60~69"); break;
	case 'D':printf("<60"); break;
	default: printf("Error"); break;  //缺少default可能导致程序什么都不能输出，如果没有匹配的情况

	}

	return 0;
}