#include <stdio.h>
#include <math.h>

int main()
{
	double a,b,c,d,e,f,g;
	a = sqrt(5);
	b = sin(50 * 3.14 / 180);
	c = fabs(-exp(2));
	d = 1/2.*a*c*c; //一定要给分子或分母加小数点！！！否则输出为0
	e = 1 / a / b / c; //即abc分之1
	f = atan2(b * 3.14 / 180, c); //即arctan(b/c)，如果认为b/c是角度则需要转换为弧度，只在分子上加即可
	g = sqrt(exp(c) / (a - b));

	printf("%.3f\n%.3f\n%.3f\n", a, b, c);

	printf("distance=%f\n", d);

	printf("%.4f\n", e);

	printf("%.4f\n", f);

	printf("%f\n", g);

	
	return 0;

}