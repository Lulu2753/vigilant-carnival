#include <stdio.h>
#include <string.h>

int main()
{
	char s[10][50];
	int n, i, j, flag;

	scanf_s("%d", &n);
	getchar();//加这个以免回车进入gets

	for (i = 0; i < n; i++)
		gets(s[i]);

	printf("\n");

	for (i = 0; i < n; i++)
	{
		flag = 0;      //是对一个字符串判断，而不是每个字符归位

		for (j = 0; j < strlen(s[i]) - 1; j++)
		{
			

			if (s[i][j] == 'P' && s[i][j + 1] == 'T' && s[i][j + 2] == 'A')
				flag = 1;

			if (s[i][strlen(s[i])-1] != '?')
				flag = 2;

		}

		if (flag == 2)
			printf("enen\n");
		else if (flag == 1)
			printf("Yes!\n");
		else
			printf("No.\n");
	}

	return 0;
	
	



}