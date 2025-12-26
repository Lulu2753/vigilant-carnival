#include <stdio.h>

struct person
{
	char name[100];
	float sal;
	float fluc;
	float out;
	float income;
}per[1000];

int main()
{
	(*per).income = 0; //只赋值了第一个，因为那是首地址，其实也可以不用初始化，因为后面在计算这个

	int i, n;
	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%s%f%f%f", per[i].name, &per[i].sal, &per[i].fluc, &per[i].out);
		per[i].income = per[i].sal + per[i].fluc - per[i].out;
	}
	
	for (i = 0; i < n; i++)
	{
		printf("%s %.2f\n", per[i].name, per[i].income);
	}

	return 0;
}
