#include <stdio.h>

int main()
{
	int n, i;
	float s, sum = 0;

	scanf_s("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf_s("%f", &s);
		sum += s;

	}

	printf("%.2f", sum / n);

	return 0;
}