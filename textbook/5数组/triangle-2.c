#include <stdio.h>

int main()
{
	int a[10][10], n, i, j;    //二维数组更好理解
	scanf_s("%d", &n);

	for (i = 0; i < n; i++)
	{
		a[i][0] = 1;
		a[i][i] = 1;
	}

	for (i = 2; i < n; i++)  //第三行开始
	{
		for (j = 1; j < i; j++)  //第二列开始，行列数一样，到倒数第二个
		{
			a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
		}
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j <= i; j++)   //行列数一样
			printf("%4d", a[i][j]);
		printf("\n");
	}

	return 0;
}