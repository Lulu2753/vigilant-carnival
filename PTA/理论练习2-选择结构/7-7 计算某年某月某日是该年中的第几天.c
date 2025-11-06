#include <stdio.h>

int main()
{
	int yyyy, mm, dd, days=0;
	scanf_s("%d-%d-%d", &yyyy, &mm, &dd);

	switch (mm-1)
	{
	
	case 11:days += 30;
	case 10:days += 31;
	case 9:days += 30;
	case 8:days += 31;
	case 7:days += 31;
	case 6:days += 30;
	case 5:days += 31;
	case 4:days += 30;
	case 3:days += 31;
	case 2:days += 28;
	case 1:days += 31;
	default:days += 0;
	}

	days = days + dd;

	if ((yyyy % 4 == 0 && yyyy % 100 != 0 || yyyy % 400 == 0) && (mm != 1 &&mm != 2))
		printf("%d", days + 1);
	else
		printf("%d", days);

	return 0;

}