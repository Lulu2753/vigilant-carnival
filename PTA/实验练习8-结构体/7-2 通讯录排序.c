#include <stdio.h>

struct friends
{
	char name[20];
	int birthday;
	char tel[17];
	long days;
};

int main()
{
	struct friends f[10];
	int n, i, j;
	scanf_s("%d", &n);

	for (i = 0; i < n; i++)
		scanf_s("%s%d%s", f[i].name, sizeof(f[i].name), & f[i].birthday, f[i].tel,sizeof(f[i].tel));

	for (i = 0; i < n; i++)
	{
		f[i].days = f[i].birthday / 10000 * 365 + (f[i].birthday % 10000) / 100 * 30 + (f[i].birthday % 10000) % 100;
	}

	

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (f[j].days > f[j + 1].days)
			{
				struct friends t = f[j];
				f[j] = f[j + 1];
				f[j + 1] = t;//年纪小的丢到后面，以交换位置的方式
			}
		}
	}

	for (i = 0; i < n; i++)
		printf("%s %d %s\n", f[i].name, f[i].birthday, f[i].tel);

	return 0;
	
}