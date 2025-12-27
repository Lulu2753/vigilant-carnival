#include <stdio.h>

int main()
{
	int a[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int * p = a, * q = p + 9;

	int sum;

	for (sum = 0; p <= q; p++)    //q--ТаїЙ
	{
		sum += *p;

	}

	printf("%d\n", sum);

	return 0;
}