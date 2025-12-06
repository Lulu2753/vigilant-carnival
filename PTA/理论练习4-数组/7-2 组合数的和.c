#include <stdio.h>

int main()
{
	int n, d[10], m[40], sum = 0, i, k = 0, j;

	scanf_s("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf_s("%d", &d[i]);
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (i != j)
			{
				m[k] = d[i] * 10 + d[j];
				sum += m[k];
				k++;    //最后再加，否则越界
				
			}
			
		}
	}

	
	printf("%d", sum);

	return 0;

}