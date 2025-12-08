#include <stdio.h>

int main()
{
	int t, n[10], i, j, k, b[10][10][10], flag;

	scanf_s("%d", &t);

	for (i = 0; i < t; i++)
	{
		scanf_s("%d", &n[i]);

		for (j = 0; j < n[i]; j++)
		{
			for (k = 0; k < n[i]; k++)
			{
				scanf_s("%d", &b[i][j][k]);     //三层需要三维
			}
		}
	}


	for (i = 0; i < t; i++)
	{
		flag = 1;

		for (j = 1; j < n[i]&&flag; j++)
		{
			for (k = 0; k < j&&flag; k++)
				if (b[i][j][k] != 0)
				{
					flag = 0;
					break;
				}
		}

		if (flag == 0)
			printf("NO\n");
		if (flag == 1)
			printf("YES\n");

	}

	return 0;

}