#include <stdio.h>

int main()
{
	int m, n, a[10][10], i, j, t, b[10][10];

	scanf_s("%d%d", &m, &n);

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			scanf_s("%d", &a[i][j]);
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			t = 0;

			if (j < n-m%n)    //列数减去移动数
				b[i][j + m % n]=a[i][j];    //不是交换
				
			else
				b[i][j - (n - m % n)]=a[i][j];    //原位置赋到新位置
	
		}

	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			printf("%d ", b[i][j]);
		printf("\n");
	}

	return 0;

}