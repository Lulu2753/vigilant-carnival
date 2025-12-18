#include <stdio.h>

int main()
{
	int a, b, * p1, * p2, c, d;

	p1 = &a; p2 = &b;

	scanf_s("%d%d", &a, &b);

	(*p1)++;       //*p++表示地址往后移一个，不是数值
	//因为*p就是a，联系紧密，这样加会让a也增加，除非新开一个变量，然后让他等于（*P）++

	c = *p1 + *p2;
	d = a + b;

	printf("%d %d\n", c, d);

	return 0;
}