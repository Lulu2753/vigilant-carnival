#include <stdio.h>
#include <string.h>

int main()
{
	char s[50];
	int i;

	gets(s);  //scanf无法读取空格，但是gets会读取scanf最后的回车，然后就回车了，读入的null，跟getchar一样

	for (i = 0; i < strlen(s); i++)
	{
		if ((s[i] >= 'A' && s[i] < 'W') || ('a' <= s[i] && s[i] < 'w'))
			s[i] += 4;
		else if (('W' <= s[i] && s[i] <= 'Z') || ('w' <= s[i] && s[i] <= 'z'))
			s[i] -= 22;
	}

	printf("%s", s);

	return 0;
}