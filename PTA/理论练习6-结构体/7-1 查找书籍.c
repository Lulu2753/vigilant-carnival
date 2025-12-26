#include <stdio.h>

struct book
{
	char name[50];
	double price;
};

int main()
{
	struct book list[10];

	int n, i, a, b;
	float max, min;   //精度
	 
	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		getchar();//scanf读不到换行，但是gets可以在一开始读到，所以用这个缓冲

		gets(list[i].name);//scanf不能读带有空格的
		//getchar();
		scanf("%lf", &list[i].price); //因为是%f格式所以读不到换行

	}

	max = min = list[0].price;
	a = b = 0;

	for (i = 0; i < n; i++)   //还是要从第一个比较起
	{
		if (list[i].price > max)
		{
			max = list[i].price;
			a = i;
		}

		if (list[i].price < min)
		{
			min = list[i].price;
			b = i;
		}
	}

	printf("%.2f, %s\n", list[a].price, list[a].name);
	printf("%.2f, %s\n", list[b].price, list[b].name);


	return 0;

}