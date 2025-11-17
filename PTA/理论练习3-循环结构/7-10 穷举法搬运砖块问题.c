#include <stdio.h>

int main()
{
	int n, a, b, c,f=0;

	scanf_s("%d", &n);

	for (a = 0; a <= n; a++)
	{
		for (b = 0; b <= n; b++)
		{
			for (c = 0; c <= n; c++)
			{
				if (a + b + c == n && 3 * a + 2 * b + c / 2.0 == n)
				{
					printf("men=%d women=%d child=%d\n", a, b, c);
					f = 1;      //作为标志，标志着有方案
				}

			}
		}
	}

	if (f != 1)
		printf("No solution!\n");

	return 0;
}
