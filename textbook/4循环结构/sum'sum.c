#include <stdio.h>

int main()
{
	int n, i=1,j,sum=0,s=0;

	scanf_s("%d", &n);

	for (; i <= n; i++)
	{
		s = 0;//s也要重置为0，因为每次是从1开始加的
		j = 1;
		for (; j <= i; j++)
			s = s + j;

		sum = sum + s;

	}

	printf("%d", sum);

	return 0;
}