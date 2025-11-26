#include <stdio.h>

int main()
{
	int i, j, k,x,y,z;

	for (i = 1; i <= 4; i++)
	{
		for (j = 1; j <= 20; j++)
			printf(" ");
		for (k = 1; k <= 5; k++)
			printf("*");
		printf("\n");

	}



	for (x = 1; x <= 4; x++)
	{
		for (y = 1; y <= x - 1; y++)
			printf(" ");
		for (z = 1; z <= 2 * x - 1; z++)
			printf("*");
		printf("\n");
	}

	return 0;
}