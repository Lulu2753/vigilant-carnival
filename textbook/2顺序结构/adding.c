#include <stdio.h>

int main()
{
	int m = 1;long p = 4l; float f = 1.0; //l或大写表示long长整型
	//以上也可以分排写
	
	double s;
	s = 'a' + 11 * m % 2 + f - p;  //%优先级在乘除之后，正负号为最高优先级，加减号最低优先级
	printf("%f", s);

	return 0;


}