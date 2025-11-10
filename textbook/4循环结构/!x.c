#include <stdio.h>

int main()

{
	int x = -3;
	do {
		printf("%d\n", x++);     //先输出x，再加1
	} while (!x);   //while(真)时才会返回循环，所以！x若为0不会返回循环，！x为1才会返回循环，所以x=0才会返回循环
}