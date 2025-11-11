#include <stdio.h>

int main()
{
	int x, y;
	
	do
	{
		system("cls");  //清屏

		y = scanf_s("%d", &x);

		if (y == 1)
			break;
	} while (1); //死循环
	

	printf("Correct!\n");

	return 0;
}
