#include <stdio.h>

int main()
{
	int x, y, z;

	for (x = 0; x <= 20; x++)
	{
		for (y = 0; y <= 33; y++)
		{
			for (z = 0; z <= 100; z++)
			{
				if (x + y + z == 100 && 5 * x + 3 * y + z / 3.0 == 100)
				{
					printf("x=%d\ty=%d\tz=%d", x, y, z);
					printf("\n");
				}
			}
		}

		
	}

	return 0;
}