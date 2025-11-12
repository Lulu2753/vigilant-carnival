#include <stdio.h>

int main()
{
	int i, j, m;
	long sum = 0, term;

	printf("Input:");
	scanf_s("%d", &m);

	for (i = 1; i <= m; i++)
	{
		term = 1;     //要在阶乘的循环前面重新变成1，否则下次阶乘是在前一个的基础上

		for (j = 1; j <= i; j++)
		{
			term = term * j;
		}

		sum = sum + term;

	}

	printf("%ld\n", sum);

	return 0;
}