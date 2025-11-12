#include <stdio.h>
int main()
{
	unsigned long long sum=0,every=1;    //unsigned long是32位，long long是64位，位数不够会溢出，可能变成负数
	int i = 1;
	double vol;

	while (i <= 64)
	{
		sum = sum + every;
		every = every*2;
		i++;
		
	}

	vol = sum / (1.42e8);  //e后面负号则是负指数，直接跟数字则是正指数

	printf("%.2f", vol);

	return 0;

}