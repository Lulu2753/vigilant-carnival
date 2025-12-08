#include <stdio.h>
#include <string.h>

int main()
{
	char s[1000];
	int i, c[1000] = { 0 }, cn = 0, flag = 0;

	gets(s);

	for (i = 0; i < strlen(s); i++)
	{
		if (s[i] != ' ' && s[i] != '\0')

		{
			flag = 1;
			c[cn]++;
			if (s[i] != ' ' && (s[i + 1] == ' ' || s[i + 1] == '\0'))
				cn++;     //先加的话前一个单词算到了下一个

		}
		
	}

	for (i = 0; i < cn; i++)
		printf("%d ", c[i]);

	if (flag == 0)
		printf("0 ");



	return 0;
}