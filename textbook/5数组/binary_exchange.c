#include <stdio.h>
#include <string.h>

int main()
{
	int n, a[16], f, i;

	scanf_s("%d", &n);

	for (i = 0; i < 16;i++)
	{
		a[15 - i] = n % 2;
		n /= 2;
	}

	for (i = 0; i < 15; i++)
		printf("%d", a[i]);

	return 0;
}