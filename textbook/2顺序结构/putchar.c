#include <stdio.h>
#include <conio.h>
int main()
{
	char c1, c2;
	printf("char=");
	c1 = getchar();//输入
	_putch(c1);     //将c1值输出至screen，是conio函数里的，等同于putchar()，输出字符本身
	printf("%4d\n", c1);  //输出ASC2码
	c2 = c1 + 32;
	putchar(c2);
	printf("%4d\n", c2);  //%4d表示左边补充空格至4位

	/*
	输入A都是对的，输入a则_putch和putchar输出结果不同，前者-127，后者？127，还没有空格
	*/


	return 0;
}