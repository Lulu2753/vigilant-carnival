#include <stdio.h>
#include <math.h>

int main()
{
	double a,b,c,d,e,f,g;
	a = sqrt(5);
	b = sin(50 * 3.14 / 180);
	c = fabs(-exp(2));
	d = 1/2.*a*c*c; //һ��Ҫ�����ӻ��ĸ��С���㣡�����������Ϊ0
	e = 1 / a / b / c; //��abc��֮1
	f = atan2(b * 3.14 / 180, c); //��arctan(b/c)�������Ϊb/c�ǽǶ�����Ҫת��Ϊ���ȣ�ֻ�ڷ����ϼӼ���
	g = sqrt(exp(c) / (a - b));

	printf("%.3f\n%.3f\n%.3f\n", a, b, c);

	printf("distance=%f\n", d);

	printf("%.4f\n", e);

	printf("%.4f\n", f);

	printf("%f\n", g);

	
	return 0;

}