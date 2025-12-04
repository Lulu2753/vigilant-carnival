#include <stdio.h>

int main()
{
	int a[10] = { 1 }, i, j, n;

	scanf_s("%d", &n);

	for (i = 0; i < n; i++)
	{
		a[0] = a[i] = 1;    //首尾为1

		for (j = i - 1; j > 0; j--)   //从倒数第二个开始，第二个为止，从后往前，且能跳过前两行
		{
			a[j] = a[j - 1] + a[j];  //覆盖上面一行的
		}

		for (j = 0; j <= i; j++)
			printf("%4d", a[j]);

		printf("\n");
	}

	return 0;
}