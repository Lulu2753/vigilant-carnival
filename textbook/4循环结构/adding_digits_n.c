#include <stdio.h>

int main()
{
	int n, dsum = 0;

	scanf_s("%d", &n);

	while (n > 0)
	{
		dsum += n % 10;
		n /=10;

	}

	printf("%d", dsum);

	return 0;
}