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
	����������һ���ģ���������ʵ������������䣬��Ϊ�������Ⱥ�˳�����Խ��һ��
	*/

	double m;
	m = 100, m=7/2.0,8; //�����һ�����ŵĽ��Ϊ׼��������һ����ֵ�ĵ�ʽ�����򲻻ḳֵ��m���˴�8����Ч
	printf("%f\n", m);

	int e, f = 7;
	float h = 4;
	e= (f = f + 6, f / h);  //�˴������ֶ��ţ�xȡ���涺�ŵļ���ֵ
	printf("e=%d\n", e);  //����õ�����������һ��Ϊint����ô���������%d����Ϊֻ��intתfloat������floatתint���������0.00000����Ҫ���float����������Ӧfloat


	return 0;
}