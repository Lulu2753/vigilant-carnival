#include <stdio.h>
#define pi 3.14159
int main()
{
	printf("Please enter the radius here:");
	float r, s;                  //定义浮点数
	scanf_s("%f", &r);           //&为取地址符号，表示“定位到”r
	s= r * r * pi;
	printf("area=%f\n", s);

	return 0;
}