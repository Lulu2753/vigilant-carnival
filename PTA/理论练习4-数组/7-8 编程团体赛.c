#include <stdio.h>

int main()
{
	int m, n, i, j, team, member,score, s[1000] = { 0 }, max, t=0;

	scanf_s("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf_s("%d-%d %d", &team,&member,&score);
		s[team] += score;
	}

	max = 0;
	for (i = 0; i < 1000; i++)
	{
		if (s[i] > max)
		{
			max = s[i];
			team = i;
		}
	}

	printf("%d %d\n", team,max);
	

	return 0;
}