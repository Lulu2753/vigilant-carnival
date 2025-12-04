#include <stdio.h>

/*输入10个及以内的分数，输入负数则停，输入大于100的数无效，但还可以继续输入*/

int main()
{
	int s[10], input, n, sum=0, count = 0, i = 0, j, t, min, max;
	float ave;

	scanf_s("%d", &input);
	while (input >= 0)
	{
		if (i < 10 && input <= 100)
		{
			s[i++] = input;
			sum += input;

			if (input < 60)     //不能抄s[i++],否则两次自增，会越界
				count++;
		}

		
		scanf_s("%d",&input);
	}

	n = i;

	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (s[i] > s[j])
			{
				t = s[i];
				s[i] = s[j];
				s[j] = t;
			}

		}
	}

	max = s[0]; min = s[0];

	for (i = 0; i < n; i++)
	{
		if (s[i] < min)
			min = s[i];
		if (s[i] > max)
			max = s[i];
			
	}

	for (i = 0; i < n; i++)
		printf("%4d", s[i]);
	printf("\n");

	printf("Failed:%d students, with %d students in total\n", count, n);

	printf("Highest:%d; Lowest:%d\n", max, min);

	ave = sum / n * 1.0;

	printf("Average:%g\n", ave);

	return 0;
}