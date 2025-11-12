#include <stdio.h>

int main()
{
	int i;
	for (i = 1; i <= 5; i++) {
		printf("\n%5d", i);
		if (i == 3)
			continue;   //直接结束当前一轮的循环，不进行后面的语句，但是后面的循环仍然继续
		printf("%5d", i);
	}

	printf("\n");

	int j;
	for (j = 1; j <= 5; j++) {
		printf("\n%5d", j);
		if (j == 3)
			break;                //也不进行后面的语句，但是直接结束循环
		printf("%5d", j);
	}




	return 0;

}