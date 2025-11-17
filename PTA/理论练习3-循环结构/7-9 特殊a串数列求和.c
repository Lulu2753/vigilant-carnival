#include <stdio.h>

int main()
{
	int a=0,n=0, i;

	scanf_s("%d%d", &a, &n);

	int b = a, sum=a;   //若在a=0那一排赋值，会导致永远为0，不会随着后面a的更新而更新

	for (i = 2; i <= n; i++)
	{
		b = 10 * b + a;   //a和多位数要区分开
		sum += b;
	}


	printf("s = %d", sum);

	return 0;
}