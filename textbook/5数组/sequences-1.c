#include <stdio.h>
/*比较法排序，与后面所有数比较*/

int main()
{
	int a[10], i, t, j;

	for (i = 0; i < 10; i++)
		scanf_s("%d", &a[i]);

	for (i = 0; i < 10; i++)
	{
		for (j = i + 1; j < 10; j++)
		{
			if (a[i] > a[j])    //会从左到右与第一个参与比较的数交换多次，改变相对位置，但最终是从小到大
			{
				t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}

		printf("Row %d:",i+1);

		for (j = 0; j < 10; j++)
			printf("%4d", a[j]);

		printf("\n");
	}

	

	return 0;

}