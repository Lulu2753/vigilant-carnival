#include <stdio.h>
#include <string.h>

int main()
{
	char s[10][50], max[50];
	int i, n;

	scanf_s("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf_s("%s", s[i],50);
	}

	strcpy_s(max, sizeof(max),s[0]);

	for (i = 0; i < n; i++)
	{
		if (strcmp(s[i], max) > 0)
			strcpy_s(max,sizeof(max), s[i]);
	}

	printf("\n%s\n", max);

	return 0;
}