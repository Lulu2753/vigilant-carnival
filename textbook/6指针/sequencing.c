#include <stdio.h>

int main()
{
	int i, j, a[10], t, * p = a;  //表示定义指针a，实际上是p=a

	srand(time(0));

	for (i = 0; i < 10; i++)
	{
		*(p + i) = rand() % 101;
		printf("%4d", *(p + i));
	}

	printf("\n");

	for (i = 0; i < 10; i++)
	{
		for (j = i + 1; j < 10; j++)   //把小的丢前面
		{
			if (*(p + j) < *(p + i))
			{
				t = *(p + j);
				*(p + j) = *(p + i);
				*(p + i) = t;
			}
		}
	}

	for (p = a; p < a + 10; p++)
		printf("%4d", *p);

	printf("\n");

	return 0;
}