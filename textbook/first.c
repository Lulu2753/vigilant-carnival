#include <stdio.h>
#define pi 3.14159
int main()
{
	printf("Please enter the radius here:");
	float r, s;                  //���帡����
	scanf_s("%f", &r);           //&Ϊȡ��ַ���ţ���ʾ����λ����r
	s= r * r * pi;
	printf("area=%f\n", s);

	return 0;
}