#include <stdio.h>
/*找到插入点后移位，从前向后循环*/
int main()
{
	int i, j, a[10], t, k,x;
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

	scanf_s("%d", &x);   //不能将插入的数存到数组，否则应当再来一遍排序，而不是这个插入算法

	for (i = 0; i < 9; i++)
	{
		if (x < a[i])   //找到就执行一次，不要再循环
		{
			for (j = 8; j >= i; j--)//从后往前移
			{
				a[j + 1] = a[j];
			}

			a[i] = x;
			break;  //插入数据后要跳出大循环
		}
	}

	for (i = 0; i < 10; i++)
		printf("%4d", a[i]);

	return 0;
	
}