#include <stdio.h>

int main()
{
	int n;
	double f, sum=0;

	for (n = 1; n <= 12; n++)
	{
		printf("Enter next data: ");
		scanf_s("%lf", &f);

		sum += f;

		system("cls");
		getchar();
	}
	printf("All data collected!");

	getchar();
	system("cls");

	printf("Average Preticipation: %.2lf\n", sum / 12.0);

	return 0;
}