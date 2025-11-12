#include <stdio.h>

int main()
{
	int i;
	for (i = 1; i <= 20; i++)
	{
		if (i % 3 == 0)
			continue;
		printf("%3d", i);
	}

	return 0;
}