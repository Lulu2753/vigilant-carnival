#include <stdio.h>
#define A "I am"
#define B "a student."  //定义字符串必须有双引号，单引号圈起来的是字符型常量，即输出ASC2值
#define SPACE " "
#define C A SPACE B  //定义的时候中间加空格没用，不会有空格

int main()
{
	printf("%s\n",A SPACE B);   //%s代表字符串，变量之间只能空格，加逗号则只会显示第一对逗号内的
	printf("%s\n",C);

	return 0;
}