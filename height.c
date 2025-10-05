#include <stdio.h>

int main()
{
	printf("Please enter the foot and inch data:");

	double foot;
	double inch;
	scanf_s("%lf %lf", &foot, &inch);
	printf("The height is %f meters.", ((foot + inch / 12.0) * 0.3048));

	return 0;
}