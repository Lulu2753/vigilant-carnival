#include <stdio.h>


int master1()
{
	int a, b, c, max;
	scanf_s("%d%d%d", &a, &b, &c);
	max = ((a >= b) ? a : (b >= c) ? b : c);

	return max;
}

double abc123()
{
	double x, y, z, s;
	scanf_s("%lf%lf%lf", &x, &y, &z);
	s = x + y + z;

	return s;  //返回这个具体的值，return 0表示什么都没返回
}

int day()
{
	int year=0, month=0, days=0,day=0;
	scanf_s("%d%d%d", &year, &month, &day);
	switch (month)
	{
	case 1: days = day; break;
	case 2: days = 31 + day; break;
	case 3: days = 31 + 28 + day; break;
	case 4: days = 31 + 28 + 31 + day; break;
	case 5: days = 31 + 28 + 31 + 30 + day; break;
	
	}
	if ((year % 4 == 0 && year % 100 != 0 || year % 400 == 0) && month != 1 && month != 2)
		days = days + 1;
	//if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		//days = days + 1; 要除去1月和2月

		
	//	printf("%d", days);
	return days;
}