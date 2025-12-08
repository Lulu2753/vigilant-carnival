#include <stdio.h>

int main()
{
	char c[10][19];    //\0也占一格，但不算一个长度
	int n, i, s[10] = { 0 }, z[10] = { 0 }, flag = -1;
	int d[17] = { 7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2 };
	char m[11] = { '1', '0', 'X', '9', '8',  '7',  '6', '5', '4', '3', '2' };

	scanf_s("%d", &n);
	getchar();  //否则后面读的空格

	for (i = 0; i < n; i++)
	{
		gets(c[i]);

	}

	for (i = 0; i < n; i++)
	{
		for (int j = 0; j < 17; j++)
			s[i] += d[j] * (c[i][j]-'0');

		z[i] = s[i] % 11;

		if (c[i][17] != m[z[i]])
		{
			flag = 1;
			printf("%s\n", c[i]);
		}
	}

	if (flag == -1)
		printf("全部正确!\n");

	return 0;
	


}