#include <stdio.h>
#include <string.h>

int main()
{
	char c[10000];
	int i;

	gets(c);

	char n[10][10] = { "ling","yi","er","san","si","wu","liu","qi","ba","jiu" };

	if (c[0] == '-')
	{
		printf("fu");
		for (i = 1; i < strlen(c); i++)
		{
			printf(" %s", n[c[i] - '0']);
		}
	}

	else
	{
		printf("%s", n[c[0]-'0']);
		for (i = 1; i < strlen(c); i++)
			printf(" %s", n[c[i] - '0']);

	}
	
	return 0;
}