#include<stdio.h>
#include<stdlib.h>
#include <string.h>

struct Records
{
	char name[20];
	char birth[9];
	char tele[21];
	long days;
};

void my_sort(struct Records* address, int N)
{
	int i, j;
	struct Records t;




	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N - i - 1; j++)
		{
			if (strcmp(address[j].name, address[j + 1].name) > 0)
			{
				struct Records t = address[j];
				address[j] = address[j + 1];
				address[j + 1] = t;//年纪小的丢到后面，以交换位置的方式
			}
		}
	}

}




int main()
{
    struct Records book[10], t;
    int i, n;

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%s %s %s", book[i].name, book[i].birth, book[i].tele);
    }

    my_sort(book, n);     // 排序函数 （function for sorting）

    for (i = 0; i < n; i++) {
        printf("%s %s %s\n", book[i].name, book[i].birth, book[i].tele);
    }
    return 0;
}

