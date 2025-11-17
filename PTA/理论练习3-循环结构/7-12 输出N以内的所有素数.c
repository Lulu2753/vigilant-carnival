#include <stdio.h>

int main()
{
	int n, i,m,flag,count=0;

	scanf_s("%d", &n);

	for (m = 2; m <= n; m++)
	{
		flag = 1;    //每一次循环前都要重置，否则一旦变为2，重新循环的时候不会变回1

		for (i = 2; i < m; i++)
			if (m % i == 0)
				flag = 2;

		if (flag == 1)
		{
			printf("%5d", m);
			count++;

			if (count % 8 == 0)
				printf("\n");   //只有在输出素数的时候才会检查换行，否则在输出合数的时候也会换行，此时count等于刚才质数时的值
		}

		
	}

	return 0;
}