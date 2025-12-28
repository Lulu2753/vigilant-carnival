#include <stdio.h>

int fun(int w);

int main()
{
	int m;
	scanf_s("%d", &m);
	printf("%d\n", fun(m));
	return 0;
}

int fun(int w)
{
	int d = 1, number;

	number = w;

	while (w > 10)
	{
		w /= 10;
		d *= 10;
	}    //否则个位数的时候也会乘一次

	return (number - d);
}