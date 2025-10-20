#include <stdio.h>

int main()
{
	int x = 1, y = 2,t;
	t = x, x = y, y = t;
	printf("%d,%d,%d\n", x,y,t);

	int a = 1, b = 2, c;
	c = a; a = b; b = c;
	printf("%d,%d,%d\n", a,b,c);

	/*
	两个本质是一样的，就是下面实际上是三个语句，因为还是有先后顺序，所以结果一样
	*/

	double m;
	m = 100, m=7/2.0,8; //以最后一个逗号的结果为准，必须是一个赋值的等式，否则不会赋值给m，此处8就无效
	printf("%f\n", m);

	int e, f = 7;
	float h = 4;
	e= (f = f + 6, f / h);  //此处就体现逗号，x取后面逗号的计算值
	printf("e=%d\n", e);  //如果用到的数字至少一个为int，那么输出必须是%d，因为只能int转float，不能float转int，否则输出0.00000，若要输出float，则两个都应float


	return 0;
}