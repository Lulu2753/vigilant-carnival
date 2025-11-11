#include <stdio.h>

int main()
{
	int f0 = 0, f1 = 1,f2,i;
	printf("%8d%8d", f0, f1);

	for (i=3; i <= 30; i++)
	{
		f2 = f0 + f1;
		printf("%8d", f2);
		
		f0 = f1;   //不能反了，是把f1的值赋给f0，f0用f1的值
		f1 = f2;

		if (i % 6 == 0)
			printf("\n");

		
	}
		
	return 0;

}