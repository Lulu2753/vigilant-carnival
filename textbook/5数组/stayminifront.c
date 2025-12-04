#include <stdio.h>

int main()
{
	int a[10], i, t=0, min, k;

	for (i = 0; i < 10; i++)
	{
		scanf_s("%d", &a[i]);

	}

	min = a[0];

	for(i=0;i<10;i++)
	{
		if (a[i] < min)    //若后面再有相等就不会交换了，即使取等交换也是一样的效果
		{
			min = a[i];
			t = i;
		}
	}

	if (t != 0)  //特定的交换，不会改变其他的相对位置
	{
		k = a[t];
		a[t] = a[0];
		a[0] = k;

	}

	for (i = 0; i < 10; i++)
		printf("%5d", a[i]);

	return 0;
	
}