#include <stdio.h>

int main()     //牛顿迭代法求根
{
	float a, x = 0, x1 = 1, f, f1;  //求x=根号a

	printf("\nInput a=");
	scanf_s("%f", &a);

	while (fabs(x1 - x) > 1e-5) {
		x = x1;
		x1 = 0.5 * (x + a / x);
	}

	printf("sqrt(%.2f)=%f\n", a, x1);
	printf("f(%f)=%.10f\n", x1, x * x - a);
	return 0;
}