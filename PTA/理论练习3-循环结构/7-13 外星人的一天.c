#include <stdio.h>

int main()
{
	int n[10], m, i, hh[10], mm[10],HH[10],MM[10],minute;

	scanf_s("%d", &m);

	for (i = 0; i <= m - 1; i++)
		scanf_s("%d %d:%d", &n[i], &hh[i], &mm[i]);

	for (i = 0; i <= m - 1; i++)
	{
		if (n[i] == 0)
			printf("%d %02d:%02d\n", n[i], hh[i], mm[i]);

		else if (n[i] == 2 || n[i] == 4 || n[i] == 6)
		{
			minute = (24 * 60 + hh[i] * 60 + mm[i])/2;
			HH[i] = minute / 60;
			MM[i] = minute % 60;
			
			
			printf("%d %02d:%02d\n", n[i]/2, HH[i], MM[i]);

		}

		else if (n[i] == 1 || n[i] == 3 || n[i] == 5)
		{
			minute = (hh[i] * 60 + mm[i]) / 2;
			HH[i] = minute / 60;
			MM[i] = minute % 60;

			printf("%d %02d:%02d\n", (n[i]+1)/2, HH[i], MM[i]);

		}
			
	}

	return 0;
}