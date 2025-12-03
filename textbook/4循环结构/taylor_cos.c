#include <stdio.h>
#include <math.h>


double ladder(long x)//输入值
{
	int i, s=1;

	for (i = 1; i <= x; i++)
	{
		s *= i;
	}

	return s;//输出值
}



int main()
{
	double cos=1,x;
	long  n,f=-1, i;

	printf("Please enter N and X:");
	scanf_s("%ld%lf", &n, &x);

	for (i = 1; i <= n; i++)
	{
		cos += f * pow(x, 2.0 * i)*1.0 / ladder(i*2);
		f = -f;

	}


	printf("cos(%g)=%.6lf\n", x,cos);

	return 0;


}