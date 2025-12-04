#include <stdio.h>

int main()
{
	int x, i, j, k;
	char ch[11][3]={ "零","壹","贰","叁","肆","伍","陆","柒","捌","玖","拾" }; //汉字为双字节码所以要2+1(\0)个长度，数组初始化只能放到定义的时候，因为{}是初始化列表

	scanf_s("%d", &x);

	i = x / 10;
	j = x % 10;

	if (i == 0)
		printf("%s", ch[j]);

	else if (j == 0)
	{
		if (i == 1)
			printf("%s", ch[10]);
		else
			printf("%s%s", ch[i], ch[10]);
	}
	else
	{

		if (i == 1)
			printf("%s%s", ch[10], ch[j]);
		else
			printf("%s%s%s", ch[i], ch[10], ch[j]);

	}
		

	return 0;



}