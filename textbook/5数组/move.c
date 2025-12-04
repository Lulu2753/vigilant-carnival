#include <stdio.h>

int main()
{
	int n, m, a[100], i, j,k;

	printf("输入n和m，输入n个数，使最后m个数移到最前面m个位置处: ");
	scanf_s("%d%d", &n,&m);

	for (i = 0; i < n; i++)
		scanf_s("%d", &a[i]);
	for (i = 0; i < n; i++)
		printf("%4d", a[i]);
	printf("\n");

	for (i = 0; i < m; i++) //向右移动m次
	{
		k = a[n - 1];//记录最后一个数
		for (j = n - 2; j >= 0; j--)  //从后往前移动
			a[j + 1] = a[j];
		a[0] = k;
	}

	for (i = 0; i < n; i++)
		printf("%4d", a[i]);
}