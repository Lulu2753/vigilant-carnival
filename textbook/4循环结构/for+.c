#include <stdio.h>

int main()
{
	int i, n, sum=0;

	for (i = 0; i < 5; i++)
	{
		scanf_s("%d", &n);
		sum = sum + n;
	}

	printf("\n%d\n", sum);

	return 0;
}