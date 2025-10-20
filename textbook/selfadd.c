#include <stdio.h>

int main()
{
	int i = 3, x;
	x = i++;
	printf("%d\n", x);//先把i=3的值赋给x，然后i自己再加1，此时i=4
	x = ++i;  //此时先i自己再加1，即i=5，再把5赋给x
	printf("%d,%d\n", x, i);


	int m, n = 10;
	++n; //直接写在这里，没有赋值符号也表示n自己加1，n++也一样的效果，因为没有把n赋值给谁
	printf("%d\n", n);

	return 0;
}