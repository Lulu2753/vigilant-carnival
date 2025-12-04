#include <stdio.h>

/*边找插入点边移位，从后向前循环，即从后往前移动*/

int main()
{
	int i, j, a[10], t, k, x;
	srand(time(0));


	for (i = 0; i < 9; i++)    //少生成一个随机数
	{
		a[i] = rand() % 101;
		printf("%4d", a[i]);


	}

	printf("\n");


	for (i = 0; i < 8; i++)
	{
		k = i;
		for (j = i + 1; j < 9; j++)//看后面的数，前面的不用管了
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

		for (j = 0; j < 9; j++)
			printf("%4d", a[j]);
		printf("\n");
	}

	printf("Enter the number to insert: ");

	scanf_s("%d", &x);

	for (i = 8; i >= 0; i--)
	{
		if (x < a[i])
			a[i + 1] = a[i];

		else
			break;//即不用再移动
	}

	a[i + 1] = x;//检索是从那个数所在位置的前一个开始，所以是i+1

	for (i = 0; i < 10; i++)
		printf("%4d", a[i]);

	return 0;


}