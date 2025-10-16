#include <stdio.h>
#define SQUARE(X) ((X)*(X))

int main()
{
	printf("Please enter the side length of the square:");
	
	int a;
	scanf_s("%d", &a);
	
	double s = SQUARE(a);
	printf("The area of the square is %.4f.\n",&s);

	return 0;
}