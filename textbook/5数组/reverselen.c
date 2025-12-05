#include <stdio.h>
#include <string.h>

int main()
{
	int i;
	char s[50];

	scanf_s("%s", s,50);  //scanf_s在string类型时最后要指定字符串大小

	for (i = strlen(s)-1; i >= 0; i--)   //用string相关函数一定要在最前面加string.h
	{
		putchar(s[i]);
	}

	printf("\n%d", strlen(s));

	return 0;
}