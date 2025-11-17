#include <stdio.h>

int main()
{
	float h1[10], h2[10];
	char ch[10],c;
	int n, i;

	scanf_s("%d", &n);

	for (i = 0; i <= n-1; i++)
	{
		while (getchar() != '\n');
		ch[i] = getchar();
		c = getchar();
		scanf_s("%f", &h1[i]);

	}

	i = 0;

	for(i=0;i<=n-1;i++)   //数组下标从0开始
	
	{
		if (ch[i] == 'M')
			h2[i] = h1[i] / 1.09;
		else if (ch[i] == 'F')
			h2[i] = h1[i]* 1.09;

		printf("%.2f\n", h2[i]);
	}

	return 0;

}