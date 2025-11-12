#include <stdio.h>



int main()
{
	int m, i, flag=1;
	char ch;

	
	while (1)
	{
		scanf_s("%d", &m);

		//ch = getchar();    //用于接收输入数字后的第一个回车

		for (i = 2; i < m; i++)
			if (m % i == 0)
				flag = 2;

		if (flag == 1)
			printf("YES\n");
		else
		{
			printf("NO\n");
			flag = 1;
		}

		system("pause");         //用来替代两个getchar()，显示Press any key to continue...
		
		
		//ch = getchar();   //用于接收显示yes和no之后的第二个回车
		system("cls");  


		
	}
	
	return 0;
}