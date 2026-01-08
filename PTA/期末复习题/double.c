#include <stdio.h>

int main()
{
	double a;

	a = (double)(7 / 2);   //会直接取整，结果是3.0；不加括号就是只对7特殊转换，再除以2

	printf("%lf", a);

	return 0;
}