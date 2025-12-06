#include <stdio.h>
#include <string.h>

int main()
{
	char city[10][20] = { "guangzhou", "wuhan", "shanghai", "beijing", "chengdu","taiyuan", "zhengzhou", "nanjing", "shijiazhuang", "tianjin" };
	char t[20];
	int i, j;

	for (i = 0; i < 9; i++)
	{
		for (j = i + 1; j < 10; j++)
		{
			if (strcmp(city[i], city[j]) > 0)
			{
				strcpy_s(t, sizeof(t), city[i]);
				strcpy_s(city[i], sizeof(city[i]), city[j]);
				strcpy_s(city[j], sizeof(city[j]), t);

			}

		}
	}

	for (i = 0; i < 10; i++)
		printf("%s\n", city[i]);//不加【i】就一直输出第一个

	return 0;

}