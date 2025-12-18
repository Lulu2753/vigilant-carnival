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
	int n = 0, new = 0, ori, digit = 1;

	ori = w;

	while (w != 0)
	{
		digit *= 10;
		w /= 10;
	}

	digit /= 10;

	new = ori % digit;

	return new;
}