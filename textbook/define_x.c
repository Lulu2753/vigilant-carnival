#include <stdio.h>
#define SQUARE(x) ((x)*(x))

int main()
{
	int a, s;
	printf("Please enter the side length of the square:");
	scanf_s("%d", &a);
	s = SQUARE(a);
	printf("The area of the square is %d\n",s);

	return 0;
}