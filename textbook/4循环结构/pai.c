#include <stdio.h>
#include <math.h>

/*用pi/4=1-1/3+1/5-1/7+…的公式求pi的近似值，直
到最后一项的绝对值小于10-6为止*/

int main()
{
	int f;  //正负号
	float n, t, pi;

	t = 1; pi = 0; n = 1.0; f = 1;

	while (fabs(t) >= 1e-6)
	{
		pi = pi + t;
		n = n + 2;
		f = -f;
		t = f / n;    //每个分数
	}

	pi = pi * 4;

	printf("%f", pi);

	return 0;
 }