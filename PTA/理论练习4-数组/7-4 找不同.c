#include <stdio.h>

int main()
{
	int s[100000], n, i, flag=0, f2 = 0, j, a = 0, count[100000] = { 0 };

	scanf_s("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf_s("%d", &s[i]);
		count[s[i]]++;

	}

	for (i = 0; i < n; i++)
	{
		if (count[s[i]] == 1)
		{
			printf("%d", s[i]);
			flag = 1;
			break;
		}

	}


	if (flag == 0)
		printf("None");


	/*双层循环会超时！！
	for (i = 0; i < n; i++)
	{

		flag = 1;                      //每次重新循环，放里面

		for (j = 0; j < n; j++)      //前面也要找不同
		{
			if (s[i] == s[j]&&i!=j)    //排除自己
				flag = 0;
			
		}


		if (flag == 1)
		{
			a = s[i];
			printf("%d", a);
			f2 = 1;
			break;

		}
			
	}

	if (f2 == 0)
		printf("None");*/

	





	return 0;
}