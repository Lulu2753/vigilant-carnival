#include <stdio.h>

int main()
{
	int a;
	for (a = 9600; a < 9700; a++)
	{
		if (a % 6 == 0 && a % 8 == 0)
			printf("%d\n", a);
	}

	return 0;
}