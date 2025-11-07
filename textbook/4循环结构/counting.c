#include <stdio.h>

int main()
{
	int i,j;

	i = 1;
	while (i <= 5)
	{
			printf("%d", i);
			i++; //先print,再加即可实现计数
	}

	printf("\n");

	j = 10;
	do {
		printf("%d", j);  //换个变量，因为上面i已经加到6了，然后6输入进去再加1，再判断能否返回，于是也有6输出来
		j++;
	} while (j <= 5);


	return 0;
}