#include <stdio.h>

int main()
{
	int repeat=0, n[10], i, j, k,m;

	scanf_s("%d", &repeat);

	for (i = 0; i <= repeat - 1; i++)
	{
		scanf_s("%d", &n[i]);
	}

	for (i = 0; i <= repeat-1 ; i++)
	{
		for (j = 1; j <= n[i]; j++)
		{
			for (k = j; k <= n[i] - 1; k++)    //每次k的起始值不一样，所以只用减1
				printf("  ");

			for (m = 1; m <= j*2-1; m++)
				printf("%d ", j);

			printf("\n");
		}
	}

	return 0;
}