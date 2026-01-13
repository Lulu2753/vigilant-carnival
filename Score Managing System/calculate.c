#include <stdio.h>
#include "functions.h"

int main()
{
	
	int i = 0;

	void psw();

	while (1)
	{
		scanf_s("%d", &info[i].term);
		if (info[i].term == 0)
			break;
		scanf_s("%s", info[i].subject, sizeof(info[i].subject));
		scanf_s("%lf%lf", &info[i].credit, &info[i].score);

		i++;
	}

	if (i > 0)
	{
		for (int j = 0; j < i; j++)
		{
			printf("%-15s", info[j].subject);
			printf("%-5d", info[j].term);
			printf("%-8.2lf", info[j].credit);
			printf("%-8.2lf", info[j].score);
			printf("\n");
		}

		double sum = 0, credits = 0;

		for (int j = 0; j < i; j++)
		{
			sum += info[j].credit * info[j].score;
			credits += info[j].credit;
		}

		sum /= credits;

		printf("%.2lf", sum);
	}
	
	

	return 0;
}