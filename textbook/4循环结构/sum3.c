#include <stdio.h>

int main()
{
	int i=1,sum=0;

	while (i <= 100)
	{
		sum += i;
		i++;
	}

	printf("%d\n", sum);

	i = 1; sum = 0;
	do
	{
		sum += i++;
	} while (i <= 100);

	printf("%d\n", sum);

	i = 1; sum = 0;
	do
	{
		sum += i;
		i++;   //由于不使用i，i++或++i在此处无区别，最终的结果仍为i加了1，只是需要调用的时候有区别：i++返回i，++i返回i+1
	} while (i <= 100);

	printf("%d\n", sum);

	for (i = 1, sum = 0; i <= 100; i++)\
	{
		sum += i;
	}

	printf("%d\n", sum);
	
	return 0;


}