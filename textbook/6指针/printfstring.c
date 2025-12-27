#include <stdio.h>

int main()
{
	char str[] = "Hello World";

	puts(str);
	puts(str + 6);    //puts自动在最后换行

	printf("%s\n", str);
	printf("%s\n", str + 6);     //从给出的地址开始打印到末尾\0

	return 0;
}