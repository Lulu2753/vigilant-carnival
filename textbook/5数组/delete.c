#include <stdio.h>

int main()
{
	int i, j, del = 0;
	int a[10] = { 1,2,3,4,5,5,7,8,9,10 }, x;

	for (i = 0; i < 10; i++)
		printf("%4d", a[i]);
	putch('\n');

	printf("Enter the number you want to delete: ");
	scanf_s("%d", &x);

	for (i = 0; i < 10-del; i++)//i++最后执行
	{
		if (x == a[i])
		{
			for (j = i; j < 10 - del; j++)
				a[j] = a[j + 1];
			
			i--;   //要停留在删掉的那个位置，没有这个会跑到删除位置的后面一个，就跳过了一个本该删掉的元素
			del++;

		}
	}

	for (i = 0; i < 10 - del; i++)
		printf("%4d", a[i]);

	return 0;
}