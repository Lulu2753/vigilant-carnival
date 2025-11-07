#include <stdio.h>

int main()
{
	int old, new = 0, count = 0;
	scanf_s("%d", &old);

	while (old > 0)
	{
		new = 10 * new + old % 10;
		old /=10 ;
		count++;
	}

	printf("%d\n", new);
	printf("Digits:%d\n", count);

	return 0;
}