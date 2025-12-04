#include <stdio.h>

int main()
{
	int a[10], i, t;

	for (i = 0; i < 10; i++)
	{
		scanf_s("%d", &a[i]);
	}

	for (i = 1; i < 10; i++)
	{
		if (a[i] < a[0])
		{
			t = a[0];
			a[0] = a[i];
			a[i] = t;

		}  //按顺序交换相对位置会变，但最终最小的在最前面


	}

	for (i = 0; i < 10; i++)
		printf("%4d", a[i]);
}