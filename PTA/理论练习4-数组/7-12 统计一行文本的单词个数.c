#include <stdio.h>

int main()
{
	char str[1000];
	int  j, cnt = 0;

	gets(str);

	for (j = 0; str[j] != '\0'; j++)
	{
		if (str[j] != ' ' && (str[j + 1] == ' ' ||str[j+1]=='\0'))    //&&优先级更高
			cnt++;
	}

	

	printf("%d\n", cnt);

	return 0;
}