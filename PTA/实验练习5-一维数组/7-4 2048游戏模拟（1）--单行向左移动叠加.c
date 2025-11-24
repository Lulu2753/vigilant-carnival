#include <stdio.h>


/*可以向左移动多次，但只能叠加一次*/


int main()
{
	int a[4], i,j,count=0;

	for (i = 0; i < 4; i++)
	{
		scanf_s("%d", &a[i]);
	}

	for (i = 0; i < 4; i++)
	{
		if (a[i] == 0)
		{
			// 找到后面非零元素

			int found = 0;  //！！！找0后面的非零元素，每次交换完之后就重置为0，看能不能再找到变成1
			for (j = i + 1; j < 4; j++)    //0022举例理解
			{
				if (a[j] != 0)
				{
					a[i] = a[j];  //0变成后面那个非0
					a[j] = 0;   //将0放到原来不是0的位置
					found = 1;
					break;//跳出for循环
				}
			}
			if (!found) break; // 表示后面没有非零元素，！found就是1，就break
		}
		
		
	}
	
	for (i = 0; i < 4; i++)
	{
		if (a[i] == a[i + 1])
		{
			a[i] *= 2;
			a[i + 1] = 0;
			//先将第二个数变成0

			for (j = i + 1; j < 3; j++)
			{
				a[j] = a[j + 1];
			}
			a[3] = 0;    //循环外面，否则重复设为0，而合并不了
		}
		  

	}
	

	printf("%d", a[0]);

	for (i = 1; i < 4; i++)
		printf(" %d", a[i]);

	return 0;
}