#include <stdio.h>

struct student
{
	int id;
	char name[20];
	int c1, c2, c3;
	float ave;
};

int main()
{
	struct student stu[10];

	int n, i, j = 0;
	float max;

	scanf_s("%d", &n);

	for (i = 0; i < n; i++)
		scanf_s("%d%s%d%d%d", &stu[i].id, stu[i].name,sizeof(stu[i].name), & stu[i].c1, &stu[i].c2, &stu[i].c3);   //姓名字符数组不加取地址
	//scanf_s对于字符串要加size！

	for (i = 0; i < n; i++)
		stu[i].ave = (stu[i].c1 + stu[i].c2 + stu[i].c3) / 3.0;
	
	max = 0;
	for (i = 0; i < n; i++)
	{
		if (stu[i].ave > max)
		{
			max = stu[i].ave;
			j = i;
		}
	}


	printf("num:%d,name:%s,average:%.2f", stu[j].id, stu[j].name, stu[j].ave);

	return 0;
}