#include <stdio.h>

int main()
{
	int i;
	for (i = 0; i < 100; i++) //这个分号用于延时输出100，去掉的话就每个i都会被输出，并且不会输出100，因为100不会进入循环；反之，循环最后自增到100，结束循环，输出100
	printf("%d\n", i);

	return 0;
}