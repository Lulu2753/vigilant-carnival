#include <stdio.h>

int main()
{
    int a = 1, b = 2, c = 3;
	a = b + 2; b = c + 3; //赋值不能赋给一个算式，只能赋给一个字母
	printf("%d\n", a);
	
	b += 3; //先前的b再加3
	printf("%d\n", b);

	a %= 3;  //将a取余的值赋给a
	printf("%d\n", a);

	double d = 2.7;
	a = d + 2; //此时a的值只与d有关，赋值的式子有先后顺序，因为a是整型，d是浮点型，所以赋到a就截断取整

	printf("%d\n", a);
	/*
	
	如果是int（1字节）赋到char（2字节），则多的那个字节流失，只保留第一个字节（截断低的八位）
	
	
	*/

	a += a /= a * a;  //因为这里a是整型，就直接截断了
	printf("%f\n", a);

	double e=6;
	e += e /= e * e;
	printf("%f\n", e);  //这里就没截断



	return 0;
}