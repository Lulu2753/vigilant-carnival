#include <stdio.h>

int main()
{
	int n, i, m=1;

	scanf_s("%d", &n);


	for (i = 1; i <= n-1; i++)
	{
		m = (m + 1) * 2;
	}

	printf("%d", m);

	return 0;
}