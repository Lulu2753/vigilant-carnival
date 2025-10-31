#include <stdio.h>
#include <math.h>

int main()
{
	float a, b, c, s, area;
	scanf_s ("%f%f%f", &a, &b, &c);

	if (a + b > c && a + c > b && b + c > a)
	{
		s = 0.5 * (a + b + c);
		area = sqrt(s * (s - a) * (s - b) * (s - c));
		printf("The area is %6.2f\n", area);

	}
	else
		printf("Data error, please reentry!");

	return 0;

}