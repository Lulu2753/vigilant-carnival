#include <stdio.h>
#define SQUARE(x) ((x)*(x))

int main()
{
	float a, s;      //float输出的结果就是对的，double就不对，好奇怪
	printf("Please enter the side length of the square:");
	scanf_s("%f", &a);
	s = SQUARE(a);
	printf("The area of the square is %.4f\n", s);  //printf不能加&！！

	return 0;
}