#include <stdio.h>

int main()
{
	int a[10];
	int* p = a, i;
	p = a;    //a是首地址

	for (; p < a + 10; p++)
		scanf("%d", p);
	printf("\n");

	for (; p < (a + 10); p++)    //a首地址不能改变，但p可以
		printf("%d", *p);  //*p++等于*(p++)，因为*和+级别相同，并且从右往左结合！(*p)++,才是内容加1
	return 0;
}

//*(p++)先返回p的地址，p本身再加一；*(++p)是先加一，再返回