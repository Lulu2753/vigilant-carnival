#include <stdio.h>

int main()
{
	char str[101];
	gets(str);

	int cnt = 0;

	for (int i = 0; str[i] != '\0'; i++)
	{
		if(str[i]!=' '&&(str[i+1]==' '||str[i+1]=='\0'))
			cnt++;
	}

	printf("%d\n", cnt);

	return 0;
}