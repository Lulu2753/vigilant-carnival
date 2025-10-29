#include <stdio.h>
int main()
{
	char ch = 'A';
	ch = ch + 32;  //A与a的ACR2码间隔32
	 
	printf("%c\n", ch);  //%c表示字符，%s表示字符串

	return 0;
}