#include <stdio.h>

int main()
{
	float x;
	int y;
	printf("x=");
	scanf_s("%f", &x);
	if (x >= 0)
		y = 1;
	if (x < 0)
		y = -1;

	printf("%.0f,%d\n", x, y);  //%g可以只保留有效数字,%.0f在这里四舍五入到整数，其他地方好像输出为0

	
	if (x - (int)x == 0)    //强制类型转换必须给int或者float打括号，而不是打到外面去
		printf("%.0f,%d\n", x, y);
	if (x - (int)x != 0)
		printf("%g,%d\n", x, y);

	return 0;

}
