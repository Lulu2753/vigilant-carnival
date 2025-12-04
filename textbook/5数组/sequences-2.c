#include <stdio.h>

/*冒泡法排序，盯着某一个数，只要后面一个比它小，就把两个交换位置，后面在比它小，就再交换，确保大的在后面*/

int main()
{
	int i, j, a[10], t;
	srand(time(0));


	for (i = 0; i < 10; i++)
	{
		a[i] = rand() % 101;
		printf("%4d", a[i]);


	}

	printf("\n");

	for (i = 0; i < 9; i++)  //9趟
	{
		for (j = 0; j < 9 - i; j++)  //每一趟放到最后面的都是最大的数，所以到那边为止，从第一个开始看
		{
			if (a[j] > a[j + 1])
			{
				t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			}
		}

		printf("Row %d: ", i);

		for (j = 0; j < 10; j++)
			printf("%4d",a[j]);
		printf("\n");
	}

	return 0;
}