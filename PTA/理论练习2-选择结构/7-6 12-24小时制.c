#include <stdio.h>

int main()
{
	int hour, minute;

	scanf_s("%d:%d", &hour, &minute);

	if (0 <= hour && hour < 12)
		printf("%d:%d AM", hour, minute);
	else if (hour == 12)
		printf("%d:%d PM", hour, minute);
	else if (12 < hour && hour <= 23)
		printf("%d:%d PM", hour - 12, minute);

	return 0;
}