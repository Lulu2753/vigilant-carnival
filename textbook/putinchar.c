#include <stdio.h>

int main()
{
	char ch;
	ch = getchar();  //专门用来输入一个字符，输入字母则转为ASC2码相加再转回去输出
	ch = ch + 3;

	putchar(ch);   //替代printf("%c\n", ch);专门用来输出一个字符,不能做到‘’内输入作为字母的ch

	putchar('\n');//单独加一个这个来换行,不直接加在ch一起

	putchar('A');

	return 0;
}