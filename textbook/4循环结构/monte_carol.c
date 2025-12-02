#include <stdio.h>
#include <stdlib.h>    //随机产生[0,32767)区间的随机数，减小区间则除

int main()
{
	int num, i, max;


		srand(time(0));  //初始化随机种子函数，产生一个以1970.1.1至当前累计秒为参数的随机序列起始值，没有这排那么下面的rand就没有种子，每次序列相同

	num = rand() % 100 + 1; //产生[1，100]的随机数    //scanf("%d", &num);  //%后面的是区间长度，开区间直接100-1，闭区间要加1，最后加的是左端点；不用除/三万多


	printf("num1=%d\n", num);

	max = num;
	for (i = 2; i <= 10; i++)
	{
		num = rand() % 100 + 1; //如果是这样输入scanf("%d", &num)，可以手动调试种子，可控制

		printf("num%d=%d\n", i, num);
		if (num > max)
			max = num;
	}
	printf("max=%d\n", max);
	return 0;

}