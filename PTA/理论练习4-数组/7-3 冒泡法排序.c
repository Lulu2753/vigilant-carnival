#include <stdio.h>

int main()
{
	int n, k, i, m[100], j, t, count = 0;

	scanf_s("%d%d", &n, &k);

	for (i = 0; i < n; i++)
		scanf_s("%d", &m[i]);

	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (m[j] > m[j + 1])
			{
				t = m[j];
				m[j] = m[j + 1];
				m[j + 1] = t;     //ÏÂ±êÊÇj£¡£¡£¡
			}
		}

		count++;

		if (count == k)
			break;
	}

	printf("%d", m[0]);

	for (i = 1; i < n; i++)
		printf(" %d", m[i]);

	return 0;


}