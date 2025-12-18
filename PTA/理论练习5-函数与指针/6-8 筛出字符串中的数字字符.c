#include <stdio.h>
#include <string.h>

void fun(char s[]);

int main()
{
	char item[80];
	gets(item);
	fun(item);
	printf("%s\n", item);
	return 0;
}


void fun(char s[])
{
	int i, count = 0;
	char n[80];
	for (i = 0; i < strlen(s); i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			n[count] = s[i];
			count++;
		}
	}
	n[count] = '\0';  //ÒªÊÕÎ²

	strcpy(s, n);

}