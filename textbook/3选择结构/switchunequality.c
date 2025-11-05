#include <stdio.h>

int main()
{
	double weight, height, BMI;
	int z;
	scanf_s("%lf%lf", &weight, &height);
	BMI = weight / height / height;
	printf("Your BMI is %.2lf\n", BMI);

	z = 1 * (BMI < 18) + 2 * (18 <= BMI && BMI < 25) + 3 * (BMI > 25);  //这里利用真值，表示连续不等式必须用&&，否则向右计算得到的必然是1，即使BMI不在范围内

	switch (z)
	{
	case 1: printf("underweight\n"); break;
	case 2: printf("Healthy\n"); break;
	case 3: printf("Overweight\n"); break;

	}
	return 0;
}