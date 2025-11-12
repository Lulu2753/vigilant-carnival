#include <stdio.h>

int main()
{
	/*
	long i, n, up1 = 2, but1 = 1, up2, but2;
	double sum=2;

	scanf_s("%ld", &n);

	for (i = 2; i <= n; i++)
	{
		
		up2 = up1 + but1;
		but2 = up1;

		up1 = up2;
		but1 = but2;   //要重新赋值给1，斐波那契都要这样

		sum += up2 * 1.0 / but2;
	}
	n到最后非常大，会溢出，所以用小数表示，如下*/  

	int i, n;
	double sum = 2,x = 2, y;

	scanf_s("%d", &n);

	for (i = 2; i <= n; i++)
	{
		y = 1 + 1.0 / x;
		x = y;
		sum += y;

	}
	
	printf("%.2lf", sum);

	return 0;

}