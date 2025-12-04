#include <stdio.h>

int main()
{
	int a[10][10], i, j, n, t;

	scanf_s("%d", &n);

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)//方形就是小于n，三角形就要小于等于i
		{
			scanf_s("%d", &a[i][j]);
		}
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%4d", a[i][j]);
		}
		printf("\n");
	}

	printf("\n");

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < i; j++)  //仍要引入中间变量，否则被覆盖
			//！！！一定要控制j<i，否则会交换两次，如a[1][2]和a[2][1]交换后，a[2][1]和a[1][2]还会交换一次，只用遍历左上半部分
		{
			t=a[i][j];
			a[i][j] = a[j][i];
			a[j][i] = t;
		}
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%4d", a[i][j]);
		}
		printf("\n");
	}

	return 0;

}