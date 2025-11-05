#include <stdio.h>

int main()
{
	char light;
	scanf_s("%c", &light);

	switch (light)
	{

	case'Y':
	case'y':
		printf("Wait"); break;
	case'G':
	case'g':
		printf("Go"); break;
	case'R':
	case'r':
		printf("Stop"); break;
	default:
		printf("Cannot go"); break;


	}

	return 0;
}