#include <stdio.h>
#include <math.h>

int main()
{
	long b = 1, f = -1;
	double esp, sum = 1, t=1;

	scanf_s("%lf", &esp);    //double对应的一定是lf，否则只会读取4节数据

	while (fabs(t) > esp)
	{
		t = 1.0 * f / (b + 3);
		sum = sum + t;
		b = b + 3;
		f = -f;


	}

	printf("sum = %f", sum);

	return 0;
}