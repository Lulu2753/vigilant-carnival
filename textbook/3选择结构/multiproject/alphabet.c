#include <stdio.h>
#include "file.h"  //自己建的文件要用引号，<>是从库里找，放到头文件调用

void main()  //void不用return
{
	char ch;
	int max;
	double y;

	scanf_s("%c", &ch);
	ch = (ch >= 'A' && ch <= 'Z') ? (ch + 32) : ch;  //赋值; ASC2码在A和Z之间
	printf("%c\n", ch);

	max =master1();
	printf("%d", max);

	y = abc123();
	printf("%g", y);

	max = day();

	printf("\n%d", max);
	//return 0;

	
}

