#include <stdio.h>

int main()
{
	int year, hour,money;
	float salary;
	scanf_s("%d %d", &year, &hour);

	if (year < 5)
		money = 30;
	else if (year >= 5)
		money = 50;             //已经确定了初始money，下一组if就是单独讨论别的变量

	if (hour <= 40)
	{
		salary = money * hour;
		printf("%.2f", salary);//不能直接两个int相乘，要相乘等于一个float再取精度
	}
	else if (hour > 40)
	{
		salary = money * 40 + money * 1.5 * (hour - 40);
		printf("%.2f", salary);
	}
	return 0;
}