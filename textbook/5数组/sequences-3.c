#include <stdio.h>

/*选择法排序，先找出最小的，再与第一个数交换（丢前面），再后面的一串数重复*/

int main()
{
	int i, j, a[10], t, k;
	srand(time(0));


	for (i = 0; i < 10; i++)
	{
		a[i] = rand() % 101;
		printf("%4d", a[i]);


	}

	printf("\n");

	for (i = 0; i < 9; i++)
	{
		k = i;
		for (j = i + 1; j < 10; j++)//看后面的数，前面的不用管了
		{
			if (a[j] < a[k])
				k = j;      //用以记录最小值下标，若直接用j则不知道是否为最小值
		}

		if (i != k)
		{
			t = a[i];
			a[i] = a[k];
			a[k] = t;
		}

		printf("Row %d: ", i);

		for (j = 0; j < 10; j++)
			printf("%4d", a[j]);
		printf("\n");
	}

	return 0;
	

}