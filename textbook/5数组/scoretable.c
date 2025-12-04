#include <stdio.h>

int main()
{
	int n, s[10][5], i, j;
	float a[5] = { 0 };

	printf("Please enter the number of students: ");
	scanf_s("%d", &n);

	for (i = 0; i < n; i++)
	{
		s[i][0] = i + 1;
		s[i][4] = 0;
		for (j = 1; j <=3; j++)
		{
			scanf_s("%d", &s[i][j]);
			s[i][4] += s[i][j];

			a[j] += s[i][j];   //一定要初始化
		
		
		}

		a[4] += s[i][4];

	}

	for (i = 1; i <= 4; i++)
		a[i] = a[i] * 1.0 / n;

	printf("学号\tC语言\t高数\t英语\t总分\n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < 5; j++)
			printf("%d\t", s[i][j]);
		printf("\n");
	}

	printf("均分\t%g\t%g\t%g\t%g\t\n", a[1], a[2], a[3], a[4]);

	return 0;




}