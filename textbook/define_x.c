#include <stdio.h>
#define SQUARE(x) ((x)*(x))

int main()
{
	float a, s;      //float����Ľ�����ǶԵģ�double�Ͳ��ԣ������
	printf("Please enter the side length of the square:");
	scanf_s("%f", &a);
	s = SQUARE(a);
	printf("The area of the square is %.4f\n", s);  //printf���ܼ�&����

	return 0;
}