#include <stdio.h>

int main()
{
	printf("123456\b89\n");  // \b 表示准备输入8的时候，光标往前挪一格，覆盖后面的进行输入
	printf("123456\b\b\b89\n");


	printf("\101 \x42 C\n");

	printf("'\101'\n");   //加上单引号则输出ASC2码代表的字符，输出也显示单引号

	printf("I say :\"How are you?\"\n");
	printf("\\C Program\\ \n");
	printf("Turbo \'C\'\n");

	return 0;
}