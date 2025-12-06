#include <stdio.h>

int main()
{
	int s[10], n, a[100], i;

	for (i = 0; i < 10; i++)
		scanf_s("%d", &s[i]);

	scanf_s("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf_s("%d", &a[i]);
		s[a[i]-1] += 10;     //ÐòºÅÒª-1£¡
	}

	printf("%d", s[0]);

	for (i = 1; i < 10; i++)
		printf(" %d", s[i]);

	return 0;


}