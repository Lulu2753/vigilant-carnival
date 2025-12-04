#include <stdio.h>

int main()
{
	char s1[15];
	char s2[2][15];
	int i;

	gets(s1); //gets（get string）后面可以放一个字符串（的首地址），返回值为指针，getchar是读取字符

	for (i = 0; i < 2; i++)
		gets(s2[i]);       //输入第i行的，也是一个字符串，要输入满2行，可以读取空格，scanf读取空格（或回车，tab）则到下一个去了  

	printf("\n");

	printf("%s", s1);  //printf遇到\0不会换行，puts会换行

	printf("\n");

	for (i = 0; i < 2; i++)
		puts(s2[i]);

}