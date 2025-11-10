#include <stdio.h>

int main()
{
	int x, y;
	
	do
	{
		system("cls");  //«Â∆¡

		y = scanf_s("%d", &x);

		if (y == 1)
			break;
	} while (1); //À¿—≠ª∑
	

	printf("Correct!\n");

	return 0;
}