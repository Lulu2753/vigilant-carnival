#include <stdio.h>

int main()
{
	int i = 0, j = 0, k = 0;
	char c;
	char m[10000], n[100000];


	while ((c = getchar()) != '\n')   //以字符形式输入
	{
		n[i] = c;
		i++;
	}

	n[i] = '\0';

	i--;

	j = i / 3 + i;

	m[j + 1] = '\0';

	for (; j >= 0; j--)
	{
		k++;
		
		if (k % 4 == 0)    //处理第三个数字才能分隔，所以3不能被整除
			m[j] = ',';
		
		else
		{
			m[j] = n[i] ;
			i--;
		}

		if (i < 0)
			break;

	}

	printf("%s", m);

	return 0;

}