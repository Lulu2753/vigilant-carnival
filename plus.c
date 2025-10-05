#include <stdio.h>

int main()
{
	int a;
	int b;

	printf("Please enter two integers:");
	scanf_s("%d,%d", &a, &b);
	printf("%d+%d=%d\n", a, b, a + b);

	return 0;
}