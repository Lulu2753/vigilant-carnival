#include <stdio.h>

int main()
{
	char s[] = "Hello World", * p;
	p = s;
	puts(p);
	p = "I love China!";   //给指针赋值，但是不会改变s[]!
	puts(p);
	puts(s);

	char* q;

	q = "Hello World";     //q指向无名字符数组，q只存放地址，字符内容存在别处；可以输出和被赋值，但不能输入；输入必须先开辟储存空间，即设立数组；
	puts(q);
	q = "I love China!";
	puts(q);

	return 0;
}