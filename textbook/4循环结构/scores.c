#include <stdio.h>

int main()
{
	int sum=0, total=0, count=0,score;

	scanf_s("%d", &score); //初始的输入以进入循环

	while (score >= 0)  //以负数作为结束标志
	{
		sum = sum + score;
		total++;

		if (score < 60)
			count++;

		scanf_s("%d", &score);
	}

	printf("Average:%.2f\n", sum * 1.0 / total);

	printf("Failed:%d", count);

}