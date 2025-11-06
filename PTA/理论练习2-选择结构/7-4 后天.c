# include <stdio.h>

int main()
{
	int d;
	scanf_s("%d", &d);

	if (1 <= d && d <= 5)
		printf("%d", d + 2);
	if (5 < d && d <= 7)
		printf("%d", d-5);

	return 0;
}