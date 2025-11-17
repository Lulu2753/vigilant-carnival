#include <stdio.h>

int main()
{
	int n[100], m, a1, a2=0, a3=0,i,f1=0,f2=0,f3=0,count=0;

	scanf_s("%d", &m);

	for (i = 0; i <= m - 1; i++)
		scanf_s("%d", &n[i]);


	a1 = n[0];

	for (i = 0; i <= m - 1; i++)
	{

		if (n[i] % 3 == 0)
		{
			f1 = 1;
			if (n[i] > a1)
				a1 = n[i];

		}
			
		if (n[i] % 3 == 1)
		{
			f2 = 1;
			a2++;
		}
			

		if (n[i] % 3 == 2)
		{
			f3 = 1;
			a3 += n[i];
			count++;
		}
			

	}

	if (f1 == 1)
		printf("%d ", a1);
	else if (f1 != 1)
		printf("NONE ");


	if (f2 == 1)
		printf("%d ", a2);
	else if (f2 != 1)
		printf("NONE ");



	if (f3 == 1)    //if里面一定不能写=，必须是==！！！
		printf("%.1f", a3*1.0/count);  //谨防不存在那个数的时候count=0的情况
	else if (f3 != 1)
		printf("NONE");

	
}