#include <stdio.h>

int main()
{
	char light;
	scanf_s("%c", &light);

	if (light == 'G' || light == 'g')
		printf("Go\n");
	if (light == 'Y' || light == 'y')  //前面加else结构更清晰
		printf("Wait");
	if (light == 'R' || light == 'r')
		printf("Stop");
	else
		printf("Cannot go");

	return 0;
}