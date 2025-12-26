#include <stdio.h>

struct students
{
	int gender;
	char name[20];
	int paired;
}stu[50];

int main()
{
	int n, i, j;
	scanf_s("%d", &n);

	for (i = 0; i < n; i++)
		scanf_s("%d%s", &stu[i].gender, stu[i].name,sizeof(stu[i].name));

	stu->paired = 0;
	//上下两种写法一个意思，注意stu是地址（指针）
	(*stu).paired = 0;

	for (i = 0; i < n; i++)
	{
		if (stu[i].paired == 0)
		{
			for (j = n - 1; j >= 0; j--)
			{
				if (stu[j].paired == 0)
				{
					if (stu[j].gender + stu[i].gender == 1)
					{
						stu[j].paired = 1;
						stu[i].paired = 1;
						printf("%s %s\n", stu[i].name, stu[j].name);
						break;
					}
				}
				
			}
		}
	}


	return 0;
}