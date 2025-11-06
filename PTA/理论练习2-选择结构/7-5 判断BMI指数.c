#include <stdio.h>

int main()
{
	float height, weight,BMI;
	int x;
	scanf_s("%f%f", &height, &weight);

	BMI = weight * 1.0 / height / height;
	x = 1 * (BMI < 18.5) + 2 * (18.5 <= BMI && BMI< 24) + 3 * (24 <= BMI && BMI < 28) + 4 * (28 <= BMI && BMI < 32) + 5 * (BMI >= 32);

	printf("BMI=%.1f\n", BMI);

	switch (x)
	{
	case 1:
		printf("Under Weight\n"); break;
	case 2:
		printf("Normal\n"); break;
	case 3:
		printf("Over Weight\n"); break;
	case 4:
		printf("Fat\n"); break;
	case 5:
		printf("Too Fat\n"); break;


	}


	return 0;
}