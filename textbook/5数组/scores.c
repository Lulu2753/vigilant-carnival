#include <stdio.h>

int main()
{
	int i, count=0;
	float ave, sum=0, s[10];

	for (i = 0; i < 10; i++)
	{
		scanf_s("%f", &s[i]);
		sum += s[i];
	}
	
	ave = sum / 10.0;

	for (i = 0; i < 10; i++)
	{
		if (s[i] >= ave)
			count++;
		
	}

	printf("Average: %g, with %d students above.\n", ave, count);

	return 0;

}